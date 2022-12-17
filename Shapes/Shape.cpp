#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}

void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

int shape::ChngBorderWidth(int BoWi)
{
	return ShpGfxInfo.BorderWdth = BoWi;
}

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}
double shape::distance(int x1, int y1, int x2, int y2) {
	double distance;
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return distance;
}
double shape:: tri_area(Point Corner1, Point Corner2, Point Corner3){
	double L1, L2, L3, hCIRCUM, AREA;
	L1 = distance(Corner1.x, Corner1.y, Corner2.x, Corner2.y);
	L2 = distance(Corner3.x, Corner3.y, Corner2.x, Corner2.y);
	L3 = distance(Corner1.x, Corner1.y, Corner3.x, Corner3.y);
	hCIRCUM =(L1 + L2 + L3)/2;
	AREA = sqrt(hCIRCUM * (hCIRCUM - L1) * (hCIRCUM - L2) * (hCIRCUM - L3));
	return AREA;
}

