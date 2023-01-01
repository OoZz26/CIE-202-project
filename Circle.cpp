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
	pUI->DrawCircle(Center, Distance, ShpGfxInfo, Hidden, unhidden, duplicated);
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
void Circle::Resize(double factor) {
	double temp = Distance;
	Distance = factor * temp;
}
string Circle::save(ofstream& savefile, string filename, string fcl, string drc, string pnw) {
	if (ShpGfxInfo.isFilled = true) {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = colortostring(ShpGfxInfo.FillClr);
		string info = "Circle " + to_string(Center.x) + " " + to_string(Center.y) + " " + to_string(Raduis.x) + " " + to_string(Raduis.y) + " " + to_string(Distance) + " " + x + " " + y;
		return info;
	}
	else {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = "NO_FILL";
		string info = "Circle " + to_string(Center.x) + " " + to_string(Center.y) + " " + to_string(Raduis.x) + " " + to_string(Raduis.y) + " " + to_string(Distance) + " " + x + " " + y;
		return info;
	}
}
