#include "opModeDraw.h"
#include "controller.h"
#include "./GUI/GUI.h"
#include "./operations/operation.h"


opModeDraw::opModeDraw(controller* pCont) : operation(pCont)
{}
opModeDraw::~opModeDraw()
{}

void opModeDraw::Undo()
{
}

void opModeDraw::Redo()
{
}

//Execute the operation
void opModeDraw::Execute() {
	GUI* pUI = pControl->GetUI();

	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();





}
