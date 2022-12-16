#include "controller.h"
#include "./GUI/GUI.h"
#include "./operations/opModeDraw.h"


opModeDraw::opModeDraw(controller* pCont) : operation(pCont)
{}
opModeDraw::~opModeDraw()
{}

//Execute the operation
void opModeDraw::Execute() {
	GUI* pUI = pControl->GetUI();

	pUI -> CreateDrawToolBar();

	pUI->ClearStatusBar();


}