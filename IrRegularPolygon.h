#pragma once
#include"Shapes/Shape.h"
class IrRegularPolygon:public shape
{
private:
	Point* Point1;
	int Vertices_num;
	int* ArrX = new int;
	int* ArrY = new int;
public:
	IrRegularPolygon(Point* p, int x, GfxInfo shapeGfxInfo);
	virtual void Resize(double factor);	//Resize the shape
	virtual void Rotate();
	void zoom(double s);
	virtual ~IrRegularPolygon();
	bool IsINSHAPE(Point test);
	virtual void Draw(GUI* pUI) const;

	string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
};

