#include "controller.h"
#include "./GUI/GUI.h"

#include "opModeDraw.h"

opModeDraw::opModeDraw(controller* pCont) : operation(pCont)
{}
opModeDraw::~opModeDraw()
{}

//Execute the operation
void opModeDraw::Execute() {
	GUI* pUI = pControl->GetUI();

	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();





}