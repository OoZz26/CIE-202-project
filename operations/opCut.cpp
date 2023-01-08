#include "opCut.h"
#include "../controller.h"
#include "../GUI/GUI.h"
opCut::opCut(controller* pCont) :operation(pCont)
{}
opCut::~opCut()
{}

void opCut::Undo()
{
}

void opCut::Redo()
{
}

shape* ShapeCut;

//Execute the operation
//
void opCut::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	if (pGraph->GetSelected() != nullptr)
	{
		pGraph->setCutShape();
		pUI->PrintMessage("THE SHAPE IS CUT");
	}
	else if (pGraph->GetSelected() == nullptr)
	{
		pUI->PrintMessage("YOU DID NOT SELECT A SHAPE TO CUT");
	}

}