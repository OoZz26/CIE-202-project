#include"Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Lenght = distance(P1.x, P1.y, P2.x, P2.y);
	ArrX[0] = Corner1.x;
	ArrY[0] = Corner1.y;
	ArrX[1] = Corner1.x + Lenght;
	ArrY[1] = Corner1.y;
	ArrX[2] = Corner1.x + Lenght;
	ArrY[2] = Corner1.y + Lenght;
	ArrX[3] = Corner1.x;
	ArrY[3] = Corner1.y + Lenght;
}



Square::~Square() {}
bool Square::IsINSHAPE(Point test) {
	Point p1, p2, p3, pr, pf;
	pf.x = ArrX[3];
	pf.y = ArrY[3];
	pr.x = ArrX[0];
	pr.y = ArrY[0];
	float area_T = 0, charea_T = 0, area_sum = 0, charea_sum = 0;
	for (int i = 0; i < 3; i++) {
		p1.x = ArrX[i];
		p1.y = ArrY[i];
		p2.x = ArrX[i + 1];
		p2.y = ArrY[i + 1];
		charea_sum = tri_area(test, p1, p2);

		area_sum = area_sum + charea_sum;
	}
	area_sum = area_sum + tri_area(test, pr, pf);


	for (int i = 0; i < 2; i++) {
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
void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pUI->DrawSQU(ArrX, ArrY, 4, ShpGfxInfo);
}string Square::save(ofstream& savefile, string filename, string fcl, string drc, string pnw) {
	if (ShpGfxInfo.isFilled = true) {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = colortostring(ShpGfxInfo.FillClr);
		string info = "Square " + to_string(Corner1.x) + " " + to_string(Corner1.y) + " " + to_string(Corner2.x) + " " + to_string(Corner2.y) + " " + to_string(Lenght) + " " + x + " " + y;
		return info;
	}
	else
	{
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = "NO_FILL";
		string info = "Square " + to_string(Corner1.x) + " " + to_string(Corner1.y) + " " + to_string(Corner2.x) + " " + to_string(Corner2.y) + " " + to_string(Lenght) + " " + x + " " + y;
		return info;
	}
}