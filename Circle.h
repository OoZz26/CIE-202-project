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
	void Move(int& e, int& s);
	void Duplicate(GUI* pUI);
	virtual ~Circle();
	int* Getshapeparameters();
	virtual void Draw(GUI* pUI) const;
	virtual bool IsINSHAPE(Point test);
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	Point GetCenter();
	Point GetRadius();
	int GetDistance();
};