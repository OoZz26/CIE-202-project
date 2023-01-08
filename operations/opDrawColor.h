#pragma once
#include <string>
#include "operation.h"

class opDrawColor : public operation
{
public:
	opDrawColor(controller* pCont);
	virtual ~opDrawColor();
	void Undo() override;
	void Redo() override;
	//Add rectangle to the controller
	virtual void Execute();

};
