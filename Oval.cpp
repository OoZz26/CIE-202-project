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
	pUI->DrawOVAL(P1, P2, ShpGfxInfo,scrambled,duplicated);
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
int* Oval::Getshapeparameters()
{
	int dis = distance(P1.x, P1.y, P2.x, P2.y);
	int list[4];
	if (P1.x < P2.x && P1.y < P2.y) {
		list[0] = P1.x - 10;
		list[1] = P1.y - 10;
		list[2] = dis+20 ;
		list[3] = dis ;
		return list;
	}
	else if (P1.x > P2.x && P1.y < P2.y) {
		list[0] = P2.x - 10;
		list[1] = P1.y - 10;
		list[2] = dis+20 ;
		list[3] = dis ;
		return list;
	}
	else if (P1.x > P2.x && P1.y > P2.y) {
		list[0] = P2.x - 10;
		list[1] = P2.y - 10;
		list[2] = dis+20 ;
		list[3] = dis ;
		return list;
	}
	else if (P1.x < P2.x && P1.y > P2.y) {
		list[0] = P1.x - 10;
		list[1] = P2.y - 10;
		list[2] = dis+20 ;
		list[3] = dis ;
		return list;
	}
}
void Oval::Move(int& e, int& s)
{
	Point center;
	center.x = ((P1.x) + (P2.x)) / 2;
	center.y = ((P1.y) + (P2.y)) / 2;
	int dx, dy;
	dx = center.x - e;
	dy = center.y - s;
	P1.x = P1.x - dx;
	P2.x = P2.x - dx;
	P1.y = P1.y - dy;
	P2.y = P2.y - dy;

	/*srand(time(0));
	double dist1y = (Corner1.y - Corner2.y);
	double dist1x = (Corner1.x - Corner2.x);
	Corner1.x = (rand() % 1000);
	Corner1.y = (rand() % 500);
	Corner2.x = Corner1.x - dist1x;
	Corner2.y = Corner1.y - dist1y;*/


}
void Oval::Duplicate(GUI* pUI) {
	P1.x = P1.x + 10;
	P2.x = P2.x + 10;
	P1.y = P1.y + 10;
	P2.y = P2.y + 10;

	//pUI->DuplicateRect(Corner1, Corner2, ShpGfxInfo);
}
void Oval::zoom(double s) {

	P1.x = s * P1.x;
	P1.y = s * P1.y;
	P2.x = s * P2.x;
	P2.y = s * P2.y;

}