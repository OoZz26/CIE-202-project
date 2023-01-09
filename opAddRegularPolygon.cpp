#include "opAddRegularPolygon.h"
#include "controller.h"
#include "GUI\GUI.h"
#include"RegularPolygon.h"






opAddRegularPolygon::opAddRegularPolygon(controller* pCont) :operation(pCont)
{}
opAddRegularPolygon::~opAddRegularPolygon()
{}

void opAddRegularPolygon::Undo()
{
	Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	pGr->pushundo(pGr2->getshapelist());
	pGr2->popShapelist();
	//GUI* pUI = pControl->GetUI();
	//pUI->PrintMessage("done");

}

void opAddRegularPolygon::Redo()
{
	//Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	//pGr->pushundo(pGr2->getshapelist());
	pGr2->popundovector();

}

//Execute the operation
void opAddRegularPolygon::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New regular Polygon: Enter number of vertices");
	//Read number of vertices
	Point Center;
	string x = pUI->GetSrting();
	Point array ;
	string msg = "Your vertices are (" + x + " )";
	msg += " ... Click on your Centerx";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(Center.x, Center.y);

	msg += " ... Click on your First Vertex";
	pUI->PrintMessage(msg);
	//Read Points
	pUI->GetPointClicked(array.x, array.y);

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
	pGr->Addshape2(R);


}

