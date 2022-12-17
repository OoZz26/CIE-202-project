#include "opFillColor.h"
#include "../controller.h"
#include "../GUI/GUI.h"
opFillColor::opFillColor(controller* pCont) :operation(pCont)
{}
opFillColor::~opFillColor()
{}

////Execute the operation
void opFillColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph * pGraph = pControl->getGraph();

	if (pGraph->GetSelected() != nullptr)
	{
		pUI->PrintMessage("CHOOSE A COLOR FROM PALETTE : ");
		color clr = pUI->CreateColorPalette();
		pGraph->GetSelected()->ChngFillClr(clr);
		pUI->ClearStatusBar();
	}

	else if (pGraph->GetSelected() == nullptr)
	{
		pUI->PrintMessage("YOU DID NOT SELECT A SHAPE ");
		color col = pUI->getCrntFillColor();


	}

	

}
