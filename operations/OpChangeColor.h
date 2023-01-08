#pragma once
#pragma once
#include <string>
#include "operation.h"
//Add Rectangle operation class
class OpChangeColor : public operation
{
public:
	string FillOrDraw;
	OpChangeColor(controller* pCont);
	virtual ~OpChangeColor();
	void Undo() override;
	void Redo() override;
	//Add rectangle to the controller
	virtual void Execute();

};
