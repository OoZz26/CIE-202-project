#pragma once

#include "Shapes/Shape.h"

class Square : public shape
{
private:
	Point Point1;
	Point Point2;
public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual string save(ofstream& savefile);
};
