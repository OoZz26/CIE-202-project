#include "RegularPolygon.h"


RegularPolygon::RegularPolygon(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	start = P1;
	end = P2;
}

RegularPolygon::~RegularPolygon()
{}

void RegularPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRPolygon(start, end, ShpGfxInfo);
}
