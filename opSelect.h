#pragma once
#include"Shapes/Rect.h"
#include"controller.h"
#include"operations/operation.h"
#include"GUI/GUI.h"

//Add select operation class
class opSelect : public operation
{
public:
	opSelect(controller* pCont);
	virtual ~opSelect();

	//Add select to the controller
	virtual void Execute();

};