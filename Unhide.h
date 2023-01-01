#pragma once
#include "operations/operation.h"
#include"Shapes/Shape.h"
#include<vector>
class opUnhide : public operation
{
	vector <shape*> Hiddenshapes2;
	vector <color> colorhidden2;
public:
	void DrawHidden(vector <shape*> hidden, vector <color> colorhiddenn, GUI* pUI);
	opUnhide(controller* pCont);
	virtual ~opUnhide();
	virtual void Execute();
};
