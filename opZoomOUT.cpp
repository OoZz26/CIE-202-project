#include "opZoomOUT.h"
#include "./controller.h"
#include "./GUI/GUI.h"
#include"operations/operation.h"
opZoomOUT::opZoomOUT(controller* pCont) :operation(pCont)
{}
opZoomOUT::~opZoomOUT()
{}

//Execute the operation

void opZoomOUT::Execute() {
	GUI* PUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	PUI->PrintMessage("CLICK to zooom out  again ");
	pGraph->ZoomOpration(0.5);
}

void opZoomOUT::Undo()
{
}

void opZoomOUT::Redo()
{
}
