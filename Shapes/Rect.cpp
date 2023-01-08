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
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo,scrambled,duplicated);
}
void Rect::Move(int&e, int&s)
{
	Point center;
	center.x = ((Corner1.x) + (Corner2.x)) / 2;
	center.y = ((Corner1.y) + (Corner2.y)) / 2;
	int dx, dy;
	dx = center.x - e;
	dy = center.y - s;
	Corner1.x = Corner1.x - dx;
	Corner2.x = Corner2.x - dx;
	Corner1.y = Corner1.y - dy;
	Corner2.y = Corner2.y - dy;
	
	
	/*srand(time(0));
	double dist1y = (Corner1.y - Corner2.y);
	double dist1x = (Corner1.x - Corner2.x);
	Corner1.x = (rand() % 1000);
	Corner1.y = (rand() % 500);
	Corner2.x = Corner1.x - dist1x;
	Corner2.y = Corner1.y - dist1y;*/


}
void Rect::scramble() {
	srand(time(0));
	double dist1y = (Corner1.y - Corner2.y);
	double dist1x = (Corner1.x - Corner2.x);
	Corner1.x = (rand() % 1000);
	Corner1.y = (rand() % 500);
	Corner2.x = Corner1.x - dist1x;
	Corner2.y = Corner1.y - dist1y;
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
void Rect::Duplicate(GUI*pUI) {
	Corner1.x = Corner1.x + 150;
	Corner2.x = Corner2.x + 150;
	Corner1.y = Corner1.y + 150;
	Corner2.y = Corner2.y + 150;
    
	//pUI->DuplicateRect(Corner1, Corner2, ShpGfxInfo);
}
int* Rect::Getshapeparameters() {
	int listofparameters[4];
	if (Corner1.x < Corner2.x && Corner1.y < Corner2.y){
		listofparameters[0] = Corner1.x - 10;
	listofparameters[1] = Corner1.y - 10;
	listofparameters[2] = abs(Corner1.x - Corner2.x) + 15;
	listofparameters[3] = abs(Corner1.y - Corner2.y) + 15;
	return listofparameters;
}
	if (Corner1.x > Corner2.x && Corner1.y < Corner2.y) {
		listofparameters[0] = Corner2.x - 10;
		listofparameters[1] = Corner1.y - 10;
		listofparameters[2] = abs(Corner1.x - Corner2.x) + 15;
		listofparameters[3] = abs(Corner1.y - Corner2.y) + 15;
		return listofparameters;
	}
	if (Corner1.x > Corner2.x && Corner1.y > Corner2.y) {
		listofparameters[0] = Corner2.x - 10;
		listofparameters[1] = Corner2.y - 10;
		listofparameters[2] = abs(Corner1.x - Corner2.x) + 15;
		listofparameters[3] = abs(Corner1.y - Corner2.y) + 15;
		return listofparameters;
	}
	if (Corner1.x < Corner2.x && Corner1.y > Corner2.y) {
		listofparameters[0] = Corner1.x - 10;
		listofparameters[1] = Corner2.y - 10;
		listofparameters[2] = abs(Corner1.x - Corner2.x) + 15;
		listofparameters[3] = abs(Corner1.y - Corner2.y) + 15;
		return listofparameters;
	}
}