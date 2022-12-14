#pragma once
#include"Shapes/Shape.h"

class RegularPolygon :public shape
{
private:
	Point Center;
	Point P;
	int radius;
	int Vertices_num;
	int* ArrX = new int;
	int* ArrY = new int;
	int vertixx;
	int vertixy;
	GfxInfo shapeGfx;
public:
	RegularPolygon(Point, Point, int, GfxInfo shapeGfxInfo);
	void Move(int& e, int& s);
	virtual void Resize(double factor);	//Resize the shape
	virtual void Rotate();
	int* Getshapeparameters();
	void Duplicate(GUI* pUI);
	virtual ~RegularPolygon();
	void Draw(GUI* pUI) const;
	bool IsINSHAPE(Point test);
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	virtual void Paste(Point p);
	shape* getPaste();
	void zoom(double s);
	shape* paste;
};