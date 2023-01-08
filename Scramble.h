#pragma once
#include "operations/operation.h"
class opScramble : public operation
{
	vector <shape*> shlist;
public:
	opScramble(controller* pCont);
	virtual ~opScramble();
	void DrawScramble(vector<shape*> duplicate, GUI* pUI, Graph* pGraph);
	virtual void Execute();
};
