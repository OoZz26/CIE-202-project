#pragma once

#include "Shapes/Shape.h"

class Square : public shape
{
private:
	Point Point1;
	Point Point2;
	int Lenght;
public:
	Square(Point p1, Point p2 ,GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
};
