#include "opZoomIN.h"
#include "./controller.h"
#include "./GUI/GUI.h"
#include"operations/operation.h"
opZoomIN::opZoomIN(controller* pCont) :operation(pCont)
{}
opZoomIN::~opZoomIN()
{}

//Execute the operation

void opZoomIN::Execute() {
	GUI* PUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	PUI->PrintMessage("z ");
	pGraph->ZoomOpration(1.5);
}
