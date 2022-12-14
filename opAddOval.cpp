#include "opAddOval.h"
#include"Oval.h"

#include "controller.h"
#include"GUI/GUI.h"
opAddOval::opAddOval(controller* pCont) :operation(pCont)
{}
opAddOval::~opAddOval()
{}

void opAddOval::Undo()
{
	Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	pGr->pushundo(pGr2->getshapelist());
	pGr2->popShapelist();
	//GUI* pUI = pControl->GetUI();
	//pUI->PrintMessage("done");

}

void opAddOval::Redo()
{
	//Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	//pGr->pushundo(pGr2->getshapelist());
	pGr2->popundovector();

}

//Execute the operation
void opAddOval::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Oval: Click at Center");
	//Read 1st point and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "The center is (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd point and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Line parameters
	GfxInfo OvalGfxInfo;

	//get drawing, filling colors and pen width from the interface
	OvalGfxInfo.DrawClr = pUI->getCrntDrawColor();
	//RectGfxInfo.FillClr = pUI->getCrntFillColor();
	OvalGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	if (pUI->getFillSt() == true)
	{
		OvalGfxInfo.FillClr = pUI->getCrntFillColor();
		OvalGfxInfo.isFilled = true;
	}
	else
	{
		OvalGfxInfo.isFilled = false;
	}

	OvalGfxInfo.isSelected = false;	//defualt is not selected


	//Create a oval with the above parameters
	Oval* R = new Oval(P1, P2, OvalGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Oval to the list of shapes
	pGr->Addshape(R);
	pGr->Addshape2(R);

}
