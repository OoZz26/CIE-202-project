#pragma once
#include"operations/operation.h"
class opAddIrRegularPolygon:public operation
{
public:
	opAddIrRegularPolygon(controller* pCont);
	virtual ~opAddIrRegularPolygon();

	//Add irregularpolygon to the controller
	virtual void Execute();
};


