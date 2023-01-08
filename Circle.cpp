#include "Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	Raduis = P2;
	Distance = distance(Center.x, Center.y, Raduis.x, Raduis.y);
}

Circle::~Circle()
{}

int* Circle::Getshapeparameters()
{
	int list[4];
	 list[0] = Center.x - Distance -10;
	 list[1] = Center.y - Distance - 10;
	 list[2] = 2*Distance + 20;
	 list[3] = 2*Distance + 20;
	 return list;
	
}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::Circle to draw a circle on the screen	
	pUI->DrawCircle(Center, Distance, ShpGfxInfo,scrambled,duplicated);
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
void Circle::Rotate() {

}
void Circle::Move(int& e, int& s)
{
		int dx, dy;
		dx = Center.x - e;
		dy = Center.y - s;
		Center.x = Center.x - dx;
		Raduis.x = Raduis.x - dx;
		Center.y = Center.y - dy;
		Raduis.y = Raduis.y - dy;
	/*Point center;
	center.x = ((Corner1.x) + (Corner2.x)) / 2;
	center.y = ((Corner1.y) + (Corner2.y)) / 2;
	int dx, dy;
	dx = center.x - e;
	dy = center.y - s;
	Corner1.x = Corner1.x - dx;
	Corner2.x = Corner2.x - dx;
	Corner1.y = Corner1.y - dy;
	Corner2.y = Corner2.y - dy;*/


	/*srand(time(0));
	double dist1y = (Corner1.y - Corner2.y);
	double dist1x = (Corner1.x - Corner2.x);
	Corner1.x = (rand() % 1000);
	Corner1.y = (rand() % 500);
	Corner2.x = Corner1.x - dist1x;
	Corner2.y = Corner1.y - dist1y;*/


}
void Circle::Duplicate(GUI* pUI) {
	Center.x = Center.x + 50;
	Center.y = Center.y + 50;
	Raduis.x = Raduis.x + 50;
	Raduis.y = Raduis.y + 50;
}