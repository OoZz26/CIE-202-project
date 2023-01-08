#include "OpChangeColor.h"
#include "../controller.h"
#include "../GUI/GUI.h"
OpChangeColor::OpChangeColor(controller* pCont) :operation(pCont)
{}
OpChangeColor::~OpChangeColor()
{}

void OpChangeColor::Undo()
{
}

void OpChangeColor::Redo()
{
}

////Execute the operation
void OpChangeColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	pUI->PrintMessage("Do you want to set 'FILL' or 'PEN' color : ");
	FillOrDraw = pUI->GetSrting();
	if (FillOrDraw == "fill")
	{
		pUI->PrintMessage("CHOOSE A COLOR FROM PALETTE : ");
		color clr = pUI->CreateColorPalette();
		pUI->getIsFilled();
		pUI->setGeneralFillColor (clr);
	}
	else if (FillOrDraw == "pen")
	{
		pUI->PrintMessage("CHOOSE A COLOR FROM PALETTE : ");
		color clr = pUI->CreateColorPalette();
		pUI->DrawColor = clr;
	}
	pUI->ClearStatusBar();

}
