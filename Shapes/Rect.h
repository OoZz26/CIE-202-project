#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	bool IsINSHAPE(Point test);
	Rect(Point , Point, GfxInfo shapeGfxInfo );


	virtual ~Rect();


	virtual void Draw(GUI* pUI) const;
};

