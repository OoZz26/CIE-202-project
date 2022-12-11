#include "opAddCircle.h"

#include"Circle.h"

#include "controller.h"
#include"GUI/GUI.h"
opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

//Execute the operation
void opAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Circle: Click at first point");
	//Read 1st point and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "The center at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd point and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Circle parameters
	GfxInfo CGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CGfxInfo.FillClr = pUI->getCrntFillColor();
	CGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	CGfxInfo.isFilled = false;	//default is not filled
	CGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Circle with the above parameters
	Circle* R = new Circle(P1, P2, CGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Circle to the list of shapes
	pGr->Addshape(R);

}


