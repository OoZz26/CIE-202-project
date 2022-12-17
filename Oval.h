#pragma once
#include"Shapes/Shape.h"

class Oval :public shape
{
private:
	Point P1;
	Point P2;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	bool IsINSHAPE(Point test);
	virtual void Draw(GUI* pUI) const;

};

