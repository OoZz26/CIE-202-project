#pragma once
#include <string>
#include "operation.h"
//Add Pen operation class
class opBorderWidth : public operation
{
public:
	int BorderChosen;
	opBorderWidth(controller* pCont);
	virtual ~opBorderWidth();
	void Undo() override;
	void Redo() override;
	//Add pen to the controller
	virtual void Execute();

};
