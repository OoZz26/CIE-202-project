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
	//Call Output::DrawSquare to draw a rectangle on the screen	
	pUI->DrawSQU(Point1, Point2, ShpGfxInfo);
}