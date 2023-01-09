#include "opMatch.h"
#include "controller.h"
#include "./GUI/GUI.h"
#include "./operations/operation.h"
#include"opModePlay.h"

opMatch::opMatch(controller* pCont) :operation(pCont)
{}
opMatch::~opMatch()
{}

//Execute the operation
void opMatch::Execute() {
	GUI* PUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->match(PUI);
	

	

	

	PUI->PrintMessage(" match ");
}