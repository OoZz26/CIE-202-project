#include "opUndo.h"
opUndo::opUndo(controller* pCont) :operation(pCont)
{}


opUndo::~opUndo()
{}

void opUndo::Undo()
{
}

void opUndo::Redo()
{
}

//Execute the operation
void opUndo::Execute()
{

	GUI* pUI = pControl->GetUI();
	if (pControl->count() > 0) {
		operation* op = pControl->topOpetrations();
	

	
		op->Undo();
		pControl->popOpeartion();
		
		

	}
	else {
		pUI->PrintMessage("Nope");
	}



}
