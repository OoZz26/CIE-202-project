#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	start = P1;
	end = P2;
}

Line::~Line()
{}
bool Line::IsINSHAPE(Point test) {
	double slope;
	slope = ((start.y) - (end.y)) / ((start.x) - (end.x));
	if (((test.y) - (start.y)) == slope * ((test.x) - (start.x)) && test.x <= max((end.x), (start.x))
		&& test.x >= min((end.y), (start.y))) {
		return true;
	}
	else
		return false;



}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawL to draw a line on the screen	
	pUI->DrawL(start, end, ShpGfxInfo);
}