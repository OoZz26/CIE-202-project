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
	color clr = pUI->CreateColorPalette();
	pUI->DrawColor = clr;

}
