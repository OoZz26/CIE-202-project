#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	start = P1;
	end = P2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawL(start, end, ShpGfxInfo);
}