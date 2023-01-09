#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual void Resize(double factor);	//Resize the shape
	virtual void Rotate();
	void Duplicate(GUI* pui);
	int* Getshapeparameters();
	virtual ~Rect();
	bool IsINSHAPE(Point test);
	virtual void Draw(GUI* pUI) const;
	void Move(int& e, int&s);
	void scramble();
	Point getP1();
	Point getP2();
	void zoom(double s);
};

