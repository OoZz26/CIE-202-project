#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}

void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

//bool shape::IsSelected() const
//{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}
int shape::distance(int x1, int y1, int x2, int y2) {
	int distance;
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return distance;
}