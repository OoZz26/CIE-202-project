#pragma once
#include "operations/operation.h"
#include<vector>
#include"Shapes/Shape.h"
#include"Shapes/Graph.h"
class opDuplicate : public operation
{
	vector <shape*> shapelist;

public:
	opDuplicate(controller* pCont);
	virtual ~opDuplicate();
	void DrawDuplicates(vector<shape*> duplicate, GUI* pUI, Graph* pGraph);
	void Undo() override;
	void Redo() override;
	virtual void Execute();
};
