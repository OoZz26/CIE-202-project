#pragma once

#include "operation.h"

class opModePlay : public operation
{
public:
	opModePlay(controller* pCont);
	virtual ~opModePlay();
	virtual void Execute();
};
