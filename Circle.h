#pragma once

#include "Shapes/shape.h"

class Circle : public shape
{
private:
	Point Center;
	Point Raduis;
	int Distance;
	
public:

	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	bool IsINSHAPE(Point test);
};