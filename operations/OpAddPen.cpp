#include "OpAddPen.h"
#include "../controller.h"
#include "../GUI/GUI.h"
OpAddPen ::OpAddPen(controller*pCont):operation(pCont)
{}
OpAddPen::~OpAddPen()
{}

////Execute the operation
void OpAddPen::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	
	pUI->PrintMessage("ENTER THE PEN WIDTH YOU NEED : ");
	PenChosen = stoi(pUI->GetSrting());
	pUI->setCrntPenWidth(PenChosen);

	//// clear the status bar
	pUI->ClearStatusBar();
}
