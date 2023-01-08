#pragma once
#include "operations/operation.h"
#include<vector>
#include"Shapes/Shape.h"
#include"Shapes/Graph.h"
class opMove : public operation
{
	vector <shape*> shapelist;

public:
	opMove(controller* pCont);
	virtual ~opMove();
	//void DrawDuplicates(vector<shape*> duplicate, GUI* pUI, Graph* pGraph);
	virtual void Execute();
};
