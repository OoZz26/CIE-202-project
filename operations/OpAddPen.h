#pragma once
#include <string>
#include "operation.h"
//Add Pen operation class
class OpAddPen : public operation
{
public:
	int PenChosen;
	OpAddPen(controller* pCont);
	virtual ~OpAddPen();
	void Undo() override;
	void Redo() override;
	//Add pen to the controller
	virtual void Execute();

};
