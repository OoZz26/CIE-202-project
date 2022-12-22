//#include"DEL.h"
#include "./controller.h"
#include"./opDel.h"
#include "./GUI/GUI.h"
#include"operations/operation.h"
#include"Shapes/Shape.h"

opDel::opDel(controller* pCont) :operation(pCont)
{}

void opDel::ActionParamerers() {
	GUI* PUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();



	pGr->DeleteShape();

	PUI->PrintMessage("Hi My friend your shape know deleted :) ");


}


//Execute the operation
void opDel::Execute()
{

	ActionParamerers();
}
