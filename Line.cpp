#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	start = P1;
	end = P2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawL to draw a line on the screen	
	pUI->DrawL(start, end, ShpGfxInfo);
}
string Line::save(ofstream& savefile) {
	string info = to_string (start.x) + "," + to_string(start.y) + "," + to_string(end.x) + "," + to_string(end.y) + "," + to_string(ShpGfxInfo.BorderWdth) + "," + to_string(ShpGfxInfo.DrawClr.ucBlue) + "," + to_string(ShpGfxInfo.FillClr.ucBlue) + "," + to_string(ShpGfxInfo.isFilled) + "," + to_string(ShpGfxInfo.isSelected) + ",";
	return info;
}