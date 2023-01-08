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
	virtual void Resize(double factor);	//Resize the shape
	virtual void Rotate();
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual bool IsINSHAPE(Point test);
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	Point GetCenter();
	Point GetRadius();
	int GetDistance();
	void zoom(double s);
};