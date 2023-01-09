#pragma once
#include"operations/operation.h"
class opZoomIN :public operation
{
public:
	opZoomIN(controller* pCont);
	void ZoomOpration(double l = 0);
	virtual ~opZoomIN();
	void Undo() override;
	void Redo() override;
	virtual void Execute();
};


