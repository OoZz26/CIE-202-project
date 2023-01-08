#pragma once
#pragma once
//#include"Shapes/Rect.h"
//#include "line.h"
//#include"IrRegularPolygon.h"
//#include"RegularPolygon.h"
//#include"Shapes/Rect.h"
//#include "Square.h"
//#include "Oval.h"
//#include "Circle.h"
//#include "Triangle.h"
#include"controller.h"
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
#include "operations/operation.h"

//Add Rotate operation class
class opRotate : public operation, public Graph
{
public:
	opRotate(controller* pCont);
	virtual ~opRotate();
	void Undo() override;
	void Redo() override;
	//Add Rotate to the controller
	virtual void Execute();


};

