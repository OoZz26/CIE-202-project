#pragma once
#include "operations/operation.h"
#include<vector>
#include"Shapes/Shape.h"
#include"Shapes/Graph.h"
class opUnhide : public operation
{
	vector <shape*> shapelist;

public:
	opUnhide(controller* pCont);
	virtual ~opUnhide();
	//void DrawDuplicates(vector<shape*> duplicate, GUI* pUI, Graph* pGraph);
	virtual void Execute();
};
