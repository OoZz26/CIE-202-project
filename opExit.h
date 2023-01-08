#pragma once
#include"operations/operation.h"
class opExit :public operation
{
public:
	opExit(controller* pCont);
	virtual ~opExit();
	void Undo() override;
	void Redo() override;
	//Add Exit to the controller
	virtual void Execute();
};

