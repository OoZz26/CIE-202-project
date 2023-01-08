#pragma once
#include "operation.h"
//Add Copy operation class
class opCut : public operation
{

public:

	opCut(controller* pCont);
	virtual ~opCut();
	void Undo() override;
	void Redo() override; 
	//Add Copy to the controller
	virtual void Execute();

};