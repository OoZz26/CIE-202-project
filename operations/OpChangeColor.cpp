#include "OpChangeColor.h"
#include "../controller.h"
#include "../GUI/GUI.h"
OpChangeColor::OpChangeColor(controller* pCont) :operation(pCont)
{}
OpChangeColor::~OpChangeColor()
{}

////Execute the operation
void OpChangeColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	pUI->PrintMessage("Do you want to 'FILL' or 'DRAW' : ");
	FillOrDraw = pUI->GetSrting();
	if (FillOrDraw == "fill")
	{
		color clr = pUI->CreateColorPalette();
		pUI->getIsFilled();
		pUI->setGeneralFillColor (clr);
	}
	else if (FillOrDraw == "draw")
	{
	
		color clr = pUI->CreateColorPalette();
		pUI->DrawColor = clr;
	}
	pUI->ClearStatusBar();

}
