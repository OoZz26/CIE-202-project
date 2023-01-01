#pragma once
#include "operations/operation.h"
#include<vector>
#include"Shapes/Shape.h"
class opHide : public operation
{
	vector <shape*> Hiddenshapes;
	vector <color> colorhidden;

public:
	void Addhiddenshape(shape* hshape,color n);
	opHide(controller* pCont);
	virtual ~opHide();
	virtual void Execute();
};
