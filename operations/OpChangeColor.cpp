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

	pUI->PrintMessage("Do you want to 'FILL' or 'DRAW' : ");
	FillOrDraw = pUI->GetSrting();
	if (FillOrDraw == "fill")
	{
		GUI* pUI = pControl->GetUI();
		color clr = pUI->CreateColorPalette();
		pUI->FillColor = clr;
	}
	else if (FillOrDraw == "draw")
	{
		GUI* pUI = pControl->GetUI();
		color clr = pUI->CreateColorPalette();
		pUI->DrawColor = clr;
	}
	pUI->ClearStatusBar();

}
