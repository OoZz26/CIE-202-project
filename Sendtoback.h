#pragma once
#include "operations/operation.h"
#include<vector>
#include"Shapes/Shape.h"
#include"Shapes/Graph.h"
class opSendtoback : public operation
{
	vector <shape*> shapelist;

public:
	opSendtoback(controller* pCont);
	virtual ~opSendtoback();
	//void DrawDuplicates(vector<shape*> duplicate, GUI* pUI, Graph* pGraph);
	virtual void Execute();
};
