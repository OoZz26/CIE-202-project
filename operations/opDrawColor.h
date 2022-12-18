#pragma once
#include <string>
#include "operation.h"

class opDrawColor : public operation
{
public:
	opDrawColor(controller* pCont);
	virtual ~opDrawColor();

	//Add rectangle to the controller
	virtual void Execute();

};
