#include "RegularPolygon.h"
#include <corecrt_math_defines.h>
#include <cmath>
RegularPolygon::RegularPolygon(Point C, Point  p, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = C;
	P = p;
	shapeGfx = shapeGfxInfo;
	
	Vertices_num = x;
	radius = distance(Center.x, Center.y, P.x, P.y);

	for (int i = 0; i < x; i++) {
		vertixx = Center.x + radius * cos(i * 2 * M_PI / x);
		vertixy = Center.y + radius * sin(i * 2 * M_PI / x);
		ArrX[i] = vertixx;
		ArrY[i] = vertixy;
	}
}
void RegularPolygon::Move(int& e, int& s)
{
	Point center;
	int n = sizeof(ArrX);
	center.x = ((ArrX[0]) + (ArrX[n-2])) / 2;
	center.y = ((ArrY[0]) + (ArrY[n-2])) / 2;
	int dx, dy;
	dx = center.x - e;
	dy = center.y - s;
	for (int i = 0; i < n; i++) {
		ArrX[i] = ArrX[i] - e;
		ArrY[i] = ArrY[i] - s;
	}
}
RegularPolygon::~RegularPolygon()
{}
bool RegularPolygon::IsINSHAPE(Point test) {
	Point p1,p2,p3,pr,pf;
	pf.x = ArrX[Vertices_num-1];
	pf.y = ArrY[Vertices_num - 1];
	pr.x = ArrX[0];
	pr.y = ArrY[0];
	float area_T=0,charea_T=0,area_sum=0,charea_sum=0;
	for (int i=0; i < Vertices_num-1; i++) {
		p1.x = ArrX[i];
		p1.y = ArrY[i];
		p2.x = ArrX[i+1];
		p2.y = ArrY[i+1];
		charea_sum= tri_area(test, p1, p2);

		area_sum = area_sum + charea_sum;
	}
	area_sum = area_sum + tri_area(test, pr, pf);
	
	
	for (int i = 0; i < Vertices_num - 2; i++) {
		p2.x = ArrX[i + 1];
		p2.y = ArrY[i + 1];
		p3.x = ArrX[i + 2];
		p3.y = ArrY[i + 2];
		charea_T= tri_area(pr, p2, p3);
		area_T = area_T + charea_T;
	}

	if (area_T == area_sum) {

		return true;
	}
	else
		return false;
}


void RegularPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRegularPolygon to draw a regularPolygon on the screen	
	pUI->DrawRPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo,scrambled,duplicated);
}
string RegularPolygon::save(ofstream& savefile, string filename, string fcl, string drc, string pnw)
{/*Center = C;
	P = p;
	Vertices_num = x;
	radius*/
	if (ShpGfxInfo.isFilled = true) {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = colortostring(ShpGfxInfo.FillClr);
		string info = "RegularPolygon " + to_string(Center.x) + " " + to_string(Center.y) + " " + to_string(P.x) + " " + to_string(P.y) + " " + to_string(Vertices_num)+ " " + to_string(radius) + " " + x + " " + y;
		return info;
	}
	else {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = "NO_FILL";
		string info = "RegularPolygon " + to_string(Center.x) + " " + to_string(Center.y) + " " + to_string(P.x) + " " + to_string(P.y) + " " + to_string(Vertices_num) + " " + to_string(radius) + " " + x + " " + y;
		return info;
	}
}
void RegularPolygon::Resize(double factor) {
	 
	for (int i = 0; i < Vertices_num; i++) {

		ArrX[i] = factor * ArrX[i] - factor * (Center.x) + (Center.x);
		ArrY[i] = factor * ArrY[i] - factor * (Center.y) + (Center.y);
	}
}
void RegularPolygon::Rotate() {



	//for (int i = 0; i < Vertices_num; i++) {

	//	int Temp1x = ArrX[i];
	//	int Temp1y = ArrY[i];
	//	ArrX[i] = -Temp1y + Center.x + Center.y;
	//	ArrY[i] = Temp1x - Center.x + Center.y;
	//
	//
	//}

}int* RegularPolygon::Getshapeparameters() {
	int listofparameters[4];
	int n = sizeof(ArrX);
		listofparameters[0] = ArrX[n-1] - 40;
		listofparameters[1] = ArrY[n-1] - 50;
		listofparameters[2] = abs(ArrX[n-1] - ArrX[1]) + 120;
		listofparameters[3] = abs(ArrY[n-1] - ArrY[1]) + 120;
		return listofparameters;
}
void RegularPolygon::Duplicate(GUI* pUI) {
	for (int i = 0; i < sizeof(ArrX); i++) {
		ArrX[i] = ArrX[i] +50;
		ArrY[i] = ArrY[i] + 50;
	}
}

void RegularPolygon::Paste(Point p)
{
	int v = Vertices_num;
	Point Ref = { p.x - Center.x,p.y - Center.y };
	//radius = distance(Center.x, Center.y, P.x, P.y);

	for (int i = 0; i < v; i++) {
		vertixx = (Ref.x / v);
		vertixy = (Ref.y / v);
		ArrX[i] = vertixx;
		ArrY[i] = vertixy;
	}

	RegularPolygon* R = new RegularPolygon(p, P, v, shapeGfx);
	paste = R;

}
shape* RegularPolygon::getPaste()
{
	return paste;
}
void RegularPolygon::zoom(double s) {
	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] = s * ArrX[i];
		ArrY[i] = s * ArrY[i];
	}
}
