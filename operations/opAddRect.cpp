#include "opAddRect.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddRect::opAddRect(controller * pCont):operation(pCont)
{}
opAddRect::~opAddRect()
{}
void opAddRect::Undo()
{
	Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	pGr->pushundo(pGr2->getshapelist());
	pGr2->popShapelist();
	//GUI* pUI = pControl->GetUI();
	//pUI->PrintMessage("done");

}

void opAddRect::Redo()
{
	//Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	//pGr->pushundo(pGr2->getshapelist());
	pGr2->popundovector();
	
}


//Execute the operation
void opAddRect::Execute() 
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Rectangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	//RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	if (pUI->getFillSt() == true)
	{
		RectGfxInfo.FillClr = pUI->getCrntFillColor();
		RectGfxInfo.isFilled = true;
	}
	else
	{
		RectGfxInfo.isFilled = false;
	}

	RectGfxInfo.isSelected = false;	//defualt is not selected

	//Create a rectangle with the above parameters
	Rect *R=new Rect(P1, P2, RectGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);
	pGr->Addshape2(R);

}




