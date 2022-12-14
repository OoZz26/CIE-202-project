#pragma once
#include "operations/operation.h"
class opLoad : public operation
{
public:
	opLoad(controller* pCont);
	virtual ~opLoad();

	virtual void Execute();
};