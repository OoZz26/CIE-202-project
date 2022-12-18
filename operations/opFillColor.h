#pragma once
#include <string>
#include "operation.h"
//Add Rectangle operation class
class opFillColor : public operation
{
public:
	string FillOrDraw;
	opFillColor(controller* pCont);
	virtual ~opFillColor();

	//Add rectangle to the controller
	virtual void Execute();

};