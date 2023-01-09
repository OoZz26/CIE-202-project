#pragma once
#include"Shapes/Shape.h"


class Line : public shape
{
private:
	Point start;
	Point end;
	int Center;
public:
	virtual void Resize(double factor) ;	//Resize the shape
	virtual void Rotate();
	int* Getshapeparameters();
	void Move(int& e, int& s);
	void Duplicate(GUI* pUI);
	void zoom(double s);
	void Duplicate();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	void getncenter(int x1 , int x2 ,int y1,int y2);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	bool IsINSHAPE(Point test);
	virtual string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
};

