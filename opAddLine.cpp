#include "opAddLine.h"

#include"Line.h"

#include "controller.h"
#include"GUI/GUI.h"
opAddLine::opAddLine(controller* pCont) :operation(pCont)
{}
opAddLine::~opAddLine()
{}

//Execute the operation
void opAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at first point");
	//Read 1st point and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd point and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Line parameters
	GfxInfo RectGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = false;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	//Line* R = new Line(P1, P2, RectGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Line to the list of shapes
	//pGr->Addshape(R);

}


