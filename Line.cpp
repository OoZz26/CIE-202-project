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
	int diff;
	
	slope = (((start.y) - (end.y))*1.0) / ((start.x) - (end.x));
	diff = abs(slope * ((test.x) - (start.x)) - ((test.y) - (start.y)));
	if (diff<=1 && test.x <= max((end.x), (start.x))
		&& test.x >= min((end.x), (start.x))) {
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