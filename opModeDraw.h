#pragma once

#include"./operations/operation.h"

class opModeDraw : public operation
{
public:
	opModeDraw(controller* pCont);
	virtual ~opModeDraw();
	void opModeDraw::Execute();

};
