#pragma once
#include"operations/operation.h"
class opAddOval : public operation
{
public:
	opAddOval(controller* pCont);
	virtual ~opAddOval();
	void Undo() override;
	void Redo() override;
	//Add Oval to the controller
	virtual void Execute();

};

