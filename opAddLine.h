#pragma once
#include"operations/operation.h"
class opAddLine : public operation
{
public:
	opAddLine(controller* pCont);
	virtual ~opAddLine();
	void Undo() override;
	void Redo() override;
	//Add line to the controller
	virtual void Execute();


};

