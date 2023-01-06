#pragma once
#include "operation.h"
//#include "Shapes/shape.h"
//Add Paste operation class
class opPaste : public operation
{
	//shape* shapePaste;
	//GfxInfo PastingShapeInfo;
private:
	//Point refPoint, P;
public:


	opPaste(controller* pCont);
	virtual ~opPaste();
	virtual void ReadActionParameters();
	//virtual void validateRectangle(Point&, Point& , Rect* );
	//virtual void validateTriangle(Point&, Point&, Rect*);
	//Add Copy to the controller


	virtual void Execute();

};
