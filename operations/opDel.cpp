//#include"DEL.h"
#include "../controller.h"
#include"./opDel.h"
#include "../GUI/GUI.h"

opDel ::opDel(controller * pCont) :operation(pCont)
{}
opDel::~opDel()
{}

//Execute the operation
void opDel::Execute()
{
	GUI* PUI = pControl->GetUI();
	PUI->PrintMessage("If you want to delete shape please select it if you do not do this first");

	Graph* pGr = pControl->getGraph();
	delete pGr->getSelected();
}


