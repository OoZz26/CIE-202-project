#include "opAddIrRegularPolygon.h"
#include"IrRegularPolygon.h"
#include "controller.h"
#include"GUI/GUI.h"



opAddIrRegularPolygon::opAddIrRegularPolygon(controller* pCont) :operation(pCont)
{}
opAddIrRegularPolygon::~opAddIrRegularPolygon()
{}

//Execute the operation
void opAddIrRegularPolygon::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New IrregularPolygon: Enter number of vertices");
	//take the number of vertices
	string x = pUI->GetSrting();
	Point* array = new Point[stoi(x)];
	string msg = "Your vertices are (" + x + " )";
	msg += " ... Click on your vertices";
	pUI->PrintMessage(msg);
	for (int i = 0; i < stoi(x); i++) {
		pUI->GetPointClicked(array[i].x, array[i].y);
	}
	pUI->ClearStatusBar();

	//Preapre all irregularPolygon parameters
	GfxInfo IrRegularPolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	IrRegularPolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	IrRegularPolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	IrRegularPolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	IrRegularPolygonGfxInfo.isFilled = false;	//default is not filled
	IrRegularPolygonGfxInfo.isSelected = false;	//defualt is not selected


	//Create an irregularPolygon with the above parameters
	IrRegularPolygon* R = new IrRegularPolygon(array,stoi(x), IrRegularPolygonGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the irregularpolygon to the list of shapes
	pGr->Addshape(R);



}
