#include"Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pUI->DrawSQU(Point1, Point2, ShpGfxInfo);
}
string Square::save(ofstream& savefile) {
	string info = to_string(Point1.x) + "," + to_string(Point1.y) + "," + to_string(Point2.x) + "," + to_string(Point2.y) + "," + to_string(ShpGfxInfo.BorderWdth) + "," + to_string(ShpGfxInfo.DrawClr.ucBlue) + "," + to_string(ShpGfxInfo.FillClr.ucBlue) + "," + to_string(ShpGfxInfo.isFilled) + "," + to_string(ShpGfxInfo.isSelected) + ",";
	return info;
	}