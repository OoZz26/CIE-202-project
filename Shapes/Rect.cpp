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
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo , Hidden, unhidden , duplicated);
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

/*void Rect::Duplicate(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	Point C1, C2;
	C1.x = Corner1.x + 10;
	C1.y = Corner1.y + 10;
	C2.x = Corner2.x + 10;
	C2.y = Corner2.y + 10;
	//pUI->setGeneralDrawColor(BLACK);
	cout << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << endl;
	cout << C1.x << " " << C1.y << " " << C2.x << " " << C2.y << endl;
	pUI->DrawRect(C1, C2 , ShpGfxInfo, Hidden, unhidden , duplicate);
	cout << "did we get here dupl??" << endl;
}*/