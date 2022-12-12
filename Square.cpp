#include"Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	Lenght = distance(P1.x, P1.y, P2.x, P2.y);
	
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pUI->DrawSQU(Point1, Lenght,ShpGfxInfo);
}