#pragma once
#include "operations/operation.h"
class opSave : public operation
{
public:
	opSave(controller* pCont);
	virtual ~opSave();
	void Undo() override;
	void Redo() override;
	virtual void Execute();
};