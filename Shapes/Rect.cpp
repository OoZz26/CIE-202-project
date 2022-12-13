#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

string Rect::save(ofstream& savefile)
{
	string info = to_string(Corner1.x) + "," + to_string(Corner1.y) + "," + to_string(Corner2.x) + "," + to_string(Corner2.y) + "," + to_string(ShpGfxInfo.BorderWdth) + "," + to_string(ShpGfxInfo.DrawClr.ucBlue) + "," + to_string(ShpGfxInfo.FillClr.ucBlue) + "," + to_string(ShpGfxInfo.isFilled) + "," + to_string(ShpGfxInfo.isSelected) + ",";
	return info;
}
