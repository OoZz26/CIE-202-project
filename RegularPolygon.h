#pragma once
#include"Shapes/Shape.h"

class RegularPolygon : public shape
{
private:

	Point start;
	Point end;
public:
	RegularPolygon(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~RegularPolygon();
	virtual void Draw(GUI* pUI) const;
};

