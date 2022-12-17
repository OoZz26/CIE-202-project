#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
bool Rect::IsINSHAPE(Point test) {
	if (test.x >= min(Corner1.x, Corner2.x) && test.x <= max(Corner1.x, Corner2.x) && test.y >= min(Corner1.y, Corner2.y) && test.y <= max(Corner1.y, Corner2.y)) {
		return true;
	}
	else
		return false;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}