#include "opResize.h"


opResize::opResize(controller* pCont) :operation(pCont)
{}


opResize::~opResize()
{}

//Execute the operation
void opResize::Execute()
{
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* s = pGraph->GetSelected();
	if (s != nullptr) {
		double factor;
		pUI->PrintMessage("Enter the Factor ");
		string x = pUI->GetSrting();
		factor = stod(x);
		s->Resize(factor);
	}
}