#include "opAddTriangle.h"
#include "Triangle.h"

#include "controller.h"

#include "GUI/GUI.h"
opAddTriangle::opAddTriangle(controller* pCont) :operation(pCont)
{}
opAddTriangle::~opAddTriangle()
{}
void opAddTriangle::Undo()
{
	Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	pGr->pushundo(pGr2->getshapelist());
	pGr2->popShapelist();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("done");

}
void opAddTriangle::Redo()
{
	//Graph* pGr = pControl->getGraph();
	Graph* pGr2 = pControl->getGraph();
	//pGr->pushundo(pGr2->getshapelist());
	pGr2->popundovector();

}
//Execute the operation
void opAddTriangle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
	msg += " ... Click at third corner";
	pUI->PrintMessage(msg);
	//Read 3rd corner and store in point P2
	pUI->GetPointClicked(P3.x, P3.y);
	pUI->ClearStatusBar();
	//Preapre all Triangle parameters
	GfxInfo TrianGfxInfo;

	TrianGfxInfo.DrawClr = pUI->getCrntDrawColor();
	//RectGfxInfo.FillClr = pUI->getCrntFillColor();
	TrianGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	if (pUI->getFillSt() == true)
	{
		TrianGfxInfo.FillClr = pUI->getCrntFillColor();
		TrianGfxInfo.isFilled = true;
	}
	else
	{
		TrianGfxInfo.isFilled = false;
	}

	TrianGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Triangle with the above parameters
	Triangle* T = new Triangle(P1, P2, P3, TrianGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Triangle to the list of shapes
	pGr->Addshape(T);
	pGr->Addshape2(T);
}
