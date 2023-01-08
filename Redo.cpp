#include "Redo.h"
opRedo::opRedo(controller* pCont) :operation(pCont)
{}


opRedo::~opRedo()
{}

void opRedo::Undo()
{
}

void opRedo::Redo()
{
}

//Execute the operation
void opRedo::Execute()
{

	GUI* pUI = pControl->GetUI();
	if (pControl->countp() > 0) {
		operation* op = pControl->topOpetrations();



		op->Redo();
		//pControl->popRedo();
		pUI->PrintMessage("done");
	}
	else {
		pUI->PrintMessage("Nope");
	}



}
