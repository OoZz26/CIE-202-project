#pragma once
#include <string>
#include "operation.h"
//Add Pen operation class
class opBorderWidth : public operation
{
public:
	int BorderChosen;
	opBorderWidth(controller* pCont);
	virtual ~opBorderWidth();

	//Add pen to the controller
	virtual void Execute();

};
