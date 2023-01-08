#pragma once
#include"operations/operation.h"
class opAddCircle : public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();
	void Undo() override;
	void Redo() override;
	//Add Circle to the controller
	virtual void Execute();


};

