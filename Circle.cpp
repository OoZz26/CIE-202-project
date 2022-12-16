#include "Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	Raduis = P2;
	Distance = distance(Center.x, Center.y, Raduis.x, Raduis.y);
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::Circle to draw a circle on the screen	
	pUI->DrawCircle(Center, Distance, ShpGfxInfo);
}
bool Circle::IsINSHAPE(Point test) {
	int d = distance(Center.x, Center.y, test.x, test.y);
	if (d <= Distance) {
		return true;
	}
	else
	{
		return false;
	}
}	
