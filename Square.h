#pragma once

#include "Shapes/Shape.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int Lenght;
public:
	Square(Point p1, Point p2 ,GfxInfo shapeGfxInfo);
	virtual ~Square();
	bool IsINSHAPE(Point test);
	virtual void Draw(GUI* pUI) const;
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
};
