#pragma once
#include"operations/operation.h"
class opAddRegularPolygon:public operation
{
public:



	opAddRegularPolygon(controller* pCont);
	virtual ~opAddRegularPolygon();

	//Add Regularpolygon to the controller
	virtual void Execute();
};

