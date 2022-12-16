#pragma once

#include"..//CIE-202-project-Hager-Ramdan/operations/operation.h"

//Add Rectangle operation class
class opExit : public operation
{
public:
	opExit(controller* pCont);
	virtual ~opExit();

	//Add rectangle to the controller
	virtual void Execute();
}
