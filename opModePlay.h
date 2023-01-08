#pragma once


#include "./operations/operation.h"

class opModePlay : public operation
{
public:
	opModePlay(controller* pCont);

	virtual ~opModePlay();
	void Undo() override;
	void Redo() override;
	virtual void Execute();
};


