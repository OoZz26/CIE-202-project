#pragma once
#include"operations/operation.h"
class opZoomOUT :public operation
{
public:
	opZoomOUT(controller* pCont);
	void ZoomOpration(double l = 0);
	virtual ~opZoomOUT();

	virtual void Execute();
};



