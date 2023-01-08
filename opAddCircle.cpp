#include "opAddCircle.h"

#include"Circle.h"

#include "controller.h"
#include"GUI/GUI.h"
opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

void opAddCircle::Undo()
{
	Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	pGr->pushundo(pGr2->getshapelist());
	pGr2->popShapelist();
	//GUI* pUI = pControl->GetUI();
	//pUI->PrintMessage("done");

}

void opAddCircle::Redo()

{
	Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();

}

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
	//Preapre all rectangle parameters
	GfxInfo CGfxInfo;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CGfxInfo.DrawClr = pUI->getCrntDrawColor();
	//RectGfxInfo.FillClr = pUI->getCrntFillColor();
	CGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	if (pUI->getFillSt() == true)
	{
		CGfxInfo.FillClr = pUI->getCrntFillColor();
		CGfxInfo.isFilled = true;
	}
	else
	{
		CGfxInfo.isFilled = false;
	}
	CGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Circle with the above parameters
	Circle* R = new Circle(P1, P2, CGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Circle to the list of shapes
	pGr->Addshape(R);
	//pGr->Addshape2(R);
}


