#pragma once
#include "operations/operation.h"
class opAddTriangle : public operation
{
public:
	opAddTriangle(controller* pCont);
	virtual ~opAddTriangle();
	void Undo() override;
	void Redo() override;
	//Add Triangle to the controller
	virtual void Execute();

};