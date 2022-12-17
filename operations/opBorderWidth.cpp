#include "opBorderWidth.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opBorderWidth::opBorderWidth(controller* pCont) :operation(pCont)
{}
opBorderWidth::~opBorderWidth()
{}

////Execute the operation
void opBorderWidth::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pUI->PrintMessage("ENTER THE BORDER WIDTH YOU NEED : ");

	if (pGraph->GetSelected() != nullptr)
	{
		BorderChosen = stoi(pUI->GetSrting());
		pGraph->GetSelected()->ChngBorderWidth(BorderChosen);
		pUI->ClearStatusBar();
	}
	else 
	{
		pUI->PrintMessage("YOU DID NOT SELECT A SHAPE ");
		BorderChosen = pUI->getCrntPenWidth();

	}


	//// clear the status bar

}