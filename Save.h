#pragma once
#include "operations/operation.h"
class opSave : public operation
{
public:
	opSave(controller* pCont);
	virtual ~opSave();

	virtual void Execute();
};