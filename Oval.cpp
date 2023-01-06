#include "Oval.h"

Oval:: Oval (Point p1, Point p2, GfxInfo shapeGfxInfo) :  shape(shapeGfxInfo)
{
	P1 = p1;
	P2 = p2;
	Distance = distance(p1.x, p1.y, p2.x, p2.y);
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
string Oval::save(ofstream& savefile, string filename, string fcl, string drc, string pnw)
{
	if (ShpGfxInfo.isFilled = true) {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = colortostring(ShpGfxInfo.FillClr);
		string info = "Oval " + to_string(P1.x) + " " + to_string(P1.y) + " " + to_string(P2.x) + " " + to_string(P2.y) + " " + x + " " + y;
		return info;
	}
	else {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = "NO_FILL";
		string info = "Oval " + to_string(P1.x) + " " + to_string(P1.y) + " " + to_string(P2.x) + " " + to_string(P2.y) + " " + x + " " + y;
		return info;
	}
}
void Oval:: Resize(double factor) {

	Point center;
	center.x = ((P1.x) + (P2.x)) / 2;
	center.y = ((P1.y) + (P2.y)) / 2;

	P1.x = factor * P1.x - factor * (center.x) + (center.x);
	P1.y = factor * P1.y - factor * (center.y) + (center.y);
	P2.x = factor * P2.x - factor * (center.x) + (center.x);
	P2.y = factor * P2.y - factor * (center.y) + (center.y);


}
void Oval:: Rotate(){
	Point center;
	center.x = ((P1.x) + (P2.x)) / 2;
	center.y = ((P1.y) + (P2.y)) / 2;

	int Temp1x = P1.x;
	int Temp1y = P1.y;
	int Temp2x = P2.x;
	int Temp2y = P2.y;

	P1.x = -Temp1y + center.x + center.y;
	P1.y = Temp1x - center.x + center.y;
	P2.x = -Temp2y + center.x + center.y;
	P2.y = Temp2x - center.x + center.y;
}

Point Oval::getP1()
{
	return P1;
}
Point Oval::getP2()
{
	return P2;
}
int Oval::GetDistance()
{
	return Distance;
}