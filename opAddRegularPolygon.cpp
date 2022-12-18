#include "opAddRegularPolygon.h"
#include "controller.h"
#include "GUI\GUI.h"
#include"RegularPolygon.h"






opAddRegularPolygon::opAddRegularPolygon(controller* pCont) :operation(pCont)
{}
opAddRegularPolygon::~opAddRegularPolygon()
{}

//Execute the operation
void opAddRegularPolygon::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New regular Polygon: Enter number of vertices");
	//Read number of vertices
	Point Center;
	string x = pUI->GetSrting();
	Point* array = new Point[stoi(x)];
	string msg = "Your vertices are (" + x + " )";
	msg += " ... Click on your Centerx";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(Center.x, Center.y);

	msg += " ... Click on your First Vertex";
	pUI->PrintMessage(msg);
	//Read Points
	pUI->GetPointClicked(array[0].x, array[0].y);

	pUI->ClearStatusBar();

	//Preapre all Irregular Polygon parameters
	GfxInfo RegularpolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RegularpolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	//RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RegularpolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	if (pUI->getFillSt() == true)
	{
		RegularpolygonGfxInfo.FillClr = pUI->getCrntFillColor();
		RegularpolygonGfxInfo.isFilled = true;
	}
	else
	{
		RegularpolygonGfxInfo.isFilled = false;
	}


	RegularpolygonGfxInfo.isSelected = false;	//defualt is not selected


	//Create an Irregular Polygon with the above parameters
	RegularPolygon* R = new RegularPolygon(Center, array, stoi(x), RegularpolygonGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the regularpolygon to the list of shapes
	pGr->Addshape(R);



}

