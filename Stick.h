#pragma once

#include "./Shapes/Shape.h"

class Stick : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Stick(Point, Point);
	virtual ~Stick();
	virtual void Draw(GUI* pUI) const;
};