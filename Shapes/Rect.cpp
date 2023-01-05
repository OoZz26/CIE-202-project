#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}
bool Rect::IsINSHAPE(Point test){
	if (test.x >= min(Corner1.x, Corner2.x) && test.x <= max(Corner1.x, Corner2.x) && test.y >= min(Corner1.y, Corner2.y) && test.y <= max(Corner1.y, Corner2.y)) {
		return true;
	}
	else
		return false;
}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
void Rect::Resize(double factor) {
	Point center;
	center.x = ((Corner1.x) + (Corner2.x) ) / 2;
	center.y = ((Corner1.y) + (Corner2.y) ) / 2;

	Corner1.x = factor * Corner1.x - factor * (center.x) + (center.x);
	Corner1.y = factor * Corner1.y - factor * (center.y) + (center.y);
	Corner2.x = factor * Corner2.x - factor * (center.x) + (center.x);
	Corner2.y = factor * Corner2.y - factor * (center.y) + (center.y);


}
void Rect::Rotate() {
	Point center;
	center.x = ((Corner1.x) + (Corner2.x)) / 2;
	center.y = ((Corner1.y) + (Corner2.y)) / 2;

	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;

	Corner1.x = -Temp1y + center.x + center.y;
	Corner1.y = Temp1x - center.x + center.y;
	Corner2.x = -Temp2y + center.x + center.y;
	Corner2.y = Temp2x - center.x + center.y;

}