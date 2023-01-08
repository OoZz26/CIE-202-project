#pragma once
#include"Shapes/Shape.h"


class Line : public shape
{
private:
	Point start;
	Point end;
public:
	virtual void Resize(double factor) ;	//Resize the shape
	virtual void Rotate();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	bool IsINSHAPE(Point test);
	virtual string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	Point GetStart();
	Point GetEnd();

	void zoom(double s);

};

