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
	void Duplicate(GUI* pUI) ;
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	int* Getshapeparameters();
	int getsmallest(int k, int n, int l);
	int getbiggest(int k, int n, int l);
	void Move(int& e, int& s);
};

