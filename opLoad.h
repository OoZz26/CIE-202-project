#pragma once
#include "operations/operation.h"
#include <sstream>
class opLoad : public operation
{
public:
	double distance(int x1, int y1, int x2, int y2);
	opLoad(controller* pCont);
	virtual ~opLoad();

	virtual void Execute();
};