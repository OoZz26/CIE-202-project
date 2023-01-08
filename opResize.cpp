#include "opResize.h"


opResize::opResize(controller* pCont) :operation(pCont)
{}


opResize::~opResize()
{}

void opResize::Undo()
{
}

void opResize::Redo()
{
}

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
		while (factor != 0.25 && factor != 0.5 && factor != 2.0 && factor != 4.0) {
			pUI->PrintMessage("ERORR,PLease enter the Factor ");
			string x = pUI->GetSrting();
			factor = stod(x);

		}

		s->Resize(factor);
	}
	else
		pUI->PrintMessage("Please select shape first");


}