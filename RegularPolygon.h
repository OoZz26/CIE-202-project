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
public:
	RegularPolygon(Point, Point, int, GfxInfo shapeGfxInfo);
	virtual ~RegularPolygon();
	void Draw(GUI* pUI) const;
	bool IsINSHAPE(Point test);
	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
};