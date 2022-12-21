#include"Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Lenght = distance(P1.x, P1.y, P2.x, P2.y);
	
}

Square::~Square()
{}
bool Square::IsINSHAPE(Point test) {
	if (test.x >= Corner1.x && test.x <= (Corner1.x)+Lenght && test.y >= Corner1.y && test.y <= (Corner1.y)+Lenght) {
		return true;
	}
	else
		return false;
}
void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pUI->DrawSQU(Corner1, Lenght,ShpGfxInfo);
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