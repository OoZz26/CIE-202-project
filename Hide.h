#pragma once
#include "operations/operation.h"
#include<vector>
#include"Shapes/Shape.h"
#include"Shapes/Graph.h"
class opHide : public operation
{
	vector <shape*> shapelist;

public:
	opHide(controller* pCont);
	virtual ~opHide();
	//void DrawDuplicates(vector<shape*> duplicate, GUI* pUI, Graph* pGraph);
	void Undo() override;
	void Redo() override;
	virtual void Execute();
};
