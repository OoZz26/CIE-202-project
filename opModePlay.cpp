#include "controller.h"
#include "./GUI/GUI.h"
#include "opModePlay.h"

opModePlay::opModePlay(controller* pCont) :operation(pCont)
{}
opModePlay::~opModePlay()
{}

//Execute the operation
void opModePlay::Execute() {
	GUI* pUI = pControl->GetUI();
	pUI->CreatePlayToolBar();

}

