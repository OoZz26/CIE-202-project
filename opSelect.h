#pragma once
#include"Shapes/Rect.h"
#include "line.h"
#include"IrRegularPolygon.h"
#include"RegularPolygon.h"
#include"Shapes/Rect.h"
#include "Square.h"
#include "Oval.h"
#include "Circle.h"
#include "Triangle.h"
#include"controller.h"
#include"operations/operation.h"
#include"GUI/GUI.h"

//Add select operation class
class opSelect : public operation
{
	vector <shape*> nshapeslist;
public:
	opSelect(controller* pCont);
	virtual ~opSelect();
	void setshapeslist(vector <shape*> shapeslist);
	//Add select to the controller
	virtual void Execute();

};