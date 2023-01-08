#pragma once
#include"operations/operation.h"
class opAddRegularPolygon:public operation
{
public:



	opAddRegularPolygon(controller* pCont);
	virtual ~opAddRegularPolygon();
	void Undo() override;
	void Redo() override;
	//Add Regularpolygon to the controller
	virtual void Execute();
};

