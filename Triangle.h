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
	virtual void Resize(double factor);	//Resize the shape
	virtual void Rotate();
	virtual ~Triangle();
	bool IsINSHAPE(Point test);
	virtual void Draw(GUI* pUI) const;
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	Point GetCorner1();
	Point GetCorner2();
	Point GetCorner3();
	void zoom(double s);
};

