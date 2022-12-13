#pragma once
#include"Shapes/Shape.h"

class Line : public shape
{
private:
	Point start;
	Point end;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual string save(ofstream& savefile);
};

