#pragma once
#include"operations/operation.h"
class opZoomIN :public operation
{
public:
	opZoomIN(controller* pCont);
	void ZoomOpration(double zoomvalue = 0);
	virtual ~opZoomIN();

	virtual void Execute();
};