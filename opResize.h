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
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
#include "operations/operation.h"

//Add select operation class
class opResize : public operation,public Graph
{
public:
	opResize(controller* pCont);
	virtual ~opResize();

	//Add Resize to the controller
	virtual void Execute();
	
	


};
