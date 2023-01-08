#pragma once

#include "Shapes/Shape.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int* ArrX = new int;
	int* ArrY = new int;
	int vertixx;
	int vertixy;
	int Lenght;
public:
	Square(Point, Point,  GfxInfo shapeGfxInfo);
	virtual void Resize(double factor);	//Resize the shape
	virtual void Rotate();
	virtual ~Square();
	bool IsINSHAPE(Point test);
	virtual void Draw(GUI* pUI) const;
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	Point getP1();
	Point getP2();

	void zoom(double s);
	
};
