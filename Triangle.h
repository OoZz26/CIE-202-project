#pragma once

#include"Shapes/Shape.h"

class Triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	Triangle(Point, Point,Point, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	bool IsINSHAPE(Point test);
	virtual void Draw(GUI* pUI) const;
};
