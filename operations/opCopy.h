#pragma once
#include "operation.h"
//Add Copy operation class
class opCopy : public operation
{

public:
	
	opCopy(controller* pCont);
	virtual ~opCopy();

	//Add Copy to the controller
	virtual void Execute();

};
