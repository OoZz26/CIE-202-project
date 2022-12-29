#include "IrRegularPolygon.h"



IrRegularPolygon::IrRegularPolygon(Point* P1, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Vertices_num = x;

	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] = Point1[i].x;
		ArrY[i] = Point1[i].y;
	}

}

IrRegularPolygon::~IrRegularPolygon()
{}
bool IrRegularPolygon::IsINSHAPE(Point test) {
	Point p1, p2, p3, pr, pf;
	pf.x = ArrX[Vertices_num - 1];
	pf.y = ArrY[Vertices_num - 1];
	pr.x = ArrX[0];
	pr.y = ArrY[0];
	float area_T = 0, charea_T = 0, area_sum = 0, charea_sum = 0;
	for (int i = 0; i < Vertices_num - 1; i++) {
		p1.x = ArrX[i];
		p1.y = ArrY[i];
		p2.x = ArrX[i + 1];
		p2.y = ArrY[i + 1];
		charea_sum = tri_area(test, p1, p2);

		area_sum = area_sum + charea_sum;
	}
	area_sum = area_sum + tri_area(test, pr, pf);


	for (int i = 0; i < Vertices_num - 2; i++) {
		p2.x = ArrX[i + 1];
		p2.y = ArrY[i + 1];
		p3.x = ArrX[i + 2];
		p3.y = ArrY[i + 2];
		charea_T = tri_area(pr, p2, p3);
		area_T = area_T + charea_T;
	}

	if (area_T == area_sum) {

		return true;
	}
	else
		return false;
}



void IrRegularPolygon::Draw(GUI* pUI) const

{

	//Call Output::IrRegularPolygon to draw a IrRegularPolygon on the screen	
	pUI->IrRegularPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo);
}
string IrRegularPolygon::save(ofstream& savefile, string filename, string fcl, string drc, string pnw)
{/*Center = C;
	P = p;
	Vertices_num = x;
	radius*/
	if (ShpGfxInfo.isFilled = true) {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = colortostring(ShpGfxInfo.FillClr);
		string info = "IrRegularPolygon " + to_string(Point1->x) + " " + to_string(Point1->y) + " " + to_string(Vertices_num) + " " + x + " " + y;
		return info;
	}
	else {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = "NO_FILL";
		string info = "IrRegularPolygon " + to_string(Point1->x) + " " + to_string(Point1->y) + " " + to_string(Vertices_num) + " " + x + " " + y;
		return info;
	}
}
void IrRegularPolygon::Resize(double factor) {
	int tempx, tempy;
	Point Center ;
	Center.x = 0;    Center.y = 0;

	for (int i = 0; i < Vertices_num; i++) {
		tempx = ArrX[i];    tempy = ArrY[i];
		(Center.x) = tempx+ Center.x;    (Center.y) = tempy+ Center.y;
		
	}

	(Center.x) = (Center.x)/ Vertices_num;    (Center.y) = (Center.y) / Vertices_num;


	for (int i = 0; i < Vertices_num; i++) {
		tempx = ArrX[i];    tempy = ArrY[i];

		ArrX[i] = factor * tempx - factor * (Center.x) + (Center.x);
		ArrY[i] = factor * tempy - factor * (Center.y) + (Center.y);
	}
}