#pragma once

#include "operation.h"

class opModeDraw : public operation
{
public:
	opModeDraw(controller* pCont);
	virtual ~opModeDraw();
	void opModeDraw::Execute();

};
