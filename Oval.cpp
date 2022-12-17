#include "Oval.h"

Oval:: Oval (Point p1, Point p2, GfxInfo shapeGfxInfo) :  shape(shapeGfxInfo)
{
	P1 = p1;
	P2 = p2;
}

Oval::~Oval()
{}
bool Oval::IsINSHAPE(Point test) {
	double a, b,check;
	Point center;
	center.x = ((P1.x) + (P2.x)) / 2;
	center.y = ((P1.y) + (P2.y)) / 2;
	a = distance(center.x, center.y, P1.x, center.y);
	b= distance(center.x, center.y, center.x,P1.y);
	check = pow(((test.x) - (center.x)) / a, 2) + pow(((test.y) - (center.y)) / b, 2);
	if (check <= 1) {
		return true;
	}
	else
		return false;
	

	
}
void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOVAL to draw a oval on the screen	
	pUI->DrawOVAL(P1, P2, ShpGfxInfo);
}