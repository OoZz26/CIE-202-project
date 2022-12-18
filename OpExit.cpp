#include "OpExit.h"
#include ".//controller.h"
#include"./GUI/GUI.h"

opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit::~opExit()
{}

//Execute the operation
void opExit::Execute() {
	GUI* PUI = pControl->GetUI();
	PUI->PrintMessage("Have a Great Day ;) ,If you want to save your art press y please :");
	string choice = PUI->GetSrting();
	PUI->exit(choice);
}

