#pragma once
#include"Shapes/Shape.h"

class Oval :public shape
{
private:
	Point P1;
	Point P2;
	int Distance;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual void Resize(double factor);	//Resize the shape
	virtual void Rotate();
	virtual ~Oval();
	bool IsINSHAPE(Point test);
	virtual void Draw(GUI* pUI) const;
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	Point getP1();
	Point getP2();
	int GetDistance();
	
};

