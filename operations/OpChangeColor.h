#pragma once
#pragma once
#include <string>
#include "operation.h"
//Add Rectangle operation class
class OpChangeColor : public operation
{
public:
	int PenChosen;
	OpChangeColor(controller* pCont);
	virtual ~OpChangeColor();

	//Add rectangle to the controller
	virtual void Execute();

};
