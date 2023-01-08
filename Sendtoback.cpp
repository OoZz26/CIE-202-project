#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "Sendtoback.h"
#include "GUI/GUI.h"
#include <fstream>
opSendtoback::opSendtoback(controller* pCont) : operation(pCont) {}
opSendtoback :: ~opSendtoback() {}

void opSendtoback::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	//shapelist = pGraph->getshapeslist();
	//DrawDuplicates(shapelist, pUI, pGraph);
	pGraph->Sendtoback(pUI);
	pUI->PrintMessage("Shape send to back");
}