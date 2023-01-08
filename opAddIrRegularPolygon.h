#pragma once
#include"operations/operation.h"
class opAddIrRegularPolygon:public operation
{
public:
	opAddIrRegularPolygon(controller* pCont);
	virtual ~opAddIrRegularPolygon();
	void Undo() override;
	void Redo() override;
	//Add irregularpolygon to the controller
	virtual void Execute();
};


