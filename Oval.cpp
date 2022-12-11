#include "Oval.h"

Oval:: Oval (Point p1, Point p2, GfxInfo shapeGfxInfo) :  shape(shapeGfxInfo)
{
	P1 = p1;
	P2 = p2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOVAL to draw a oval on the screen	
	pUI->DrawOVAL(P1, P2, ShpGfxInfo);
}