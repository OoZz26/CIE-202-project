#include "RegularPolygon.h"
#include <corecrt_math_defines.h>
#include <cmath>
RegularPolygon::RegularPolygon(Point C, Point  p, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = C;
	P = p;

	
	Vertices_num = x;
	radius = distance(Center.x, Center.y, P.x, P .y);

	for (int i = 0; i < x; i++) {
		vertixx = Center.x + radius * cos(i * 2 * M_PI / x);
		vertixy = Center.y + radius * sin(i * 2 * M_PI / x);
		ArrX[i] = vertixx;
		ArrY[i] = vertixy;
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
	pUI->DrawRPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo);
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