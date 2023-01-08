#include "opDrawColor.h"
#include "../controller.h"
#include "../GUI/GUI.h"
opDrawColor::opDrawColor(controller* pCont) :operation(pCont)
{}
opDrawColor::~opDrawColor()
{}

void opDrawColor::Undo()
{
}

void opDrawColor::Redo()
{
}

////Execute the operation
void opDrawColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	if (pGraph->GetSelected() != nullptr)
	{
		pUI->PrintMessage("CHOOSE A COLOR FROM PALETTE : ");
		color clr = pUI->CreateColorPalette();
		pGraph->GetSelected()->ChngDrawClr(clr);
		pUI->ClearStatusBar();
	}
	else if (pGraph->GetSelected() == nullptr)
	{
		pUI->PrintMessage("YOU DID NOT SELECT A SHAPE ");
		color col = pUI->getCrntDrawColor();


	}



}