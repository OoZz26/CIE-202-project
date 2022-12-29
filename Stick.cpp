#include "stick.h"

Stick::Stick(Point P1,  Point P2)
{
	Corner1 = P1;
	Corner2 = P2;
}

Stick::~Stick()
{}

void Stick::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	string sticki = "images\\MenuIcons\\stick.jpg";

	
	pUI->stickImage(sticki,Corner1, Corner2);
}