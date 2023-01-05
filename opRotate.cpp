#include "opRotate.h"
opRotate::opRotate(controller* pCont) :operation(pCont)
{}


opRotate::~opRotate()
{}

//Execute the operation
void opRotate::Execute()
{
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* s = pGraph->GetSelected();
	if (s) {
		s->Rotate();
	}
	else {
		pUI->PrintMessage("Please select shape first");
	}
 


}
