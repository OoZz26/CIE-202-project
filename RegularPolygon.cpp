#include "RegularPolygon.h"
#include <corecrt_math_defines.h>
#include <cmath>
RegularPolygon::RegularPolygon(Point C, Point * p, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = C;
	P = p;
	Vertices_num = x;
	radius = distance(Center.x, Center.y, P->x, P ->y);

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
	Point p1,p2,pr,pf;
	pf.x = ArrX[Vertices_num-1];
	pf.y = ArrY[Vertices_num - 1];
	pr.x = ArrX[0];
	pr.y = ArrY[0];
	float area_T=0,charea_T=0,area_sum=0,charea_sum=0;
	for (int i; i < Vertices_num; i++) {
		p1.x = ArrX[i];
		p1.y = ArrY[i];
		p2.x = ArrX[i+1];
		p2.y = ArrY[i+1];
		charea_sum= tri_area(test, p1, p2);
		area_sum = area_sum + charea_sum;
		charea_T= tri_area(pr, p1, p2);
		area_T = area_T + charea_T;
	}
	area_sum = area_sum + tri_area(test, pr, pf);
	cout << area_T << "\t" << area_sum;
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
