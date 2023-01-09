#pragma once
#include "operation.h"

class opStartGame : public operation
{ 
private:
	int matchCounter = 0;
	int MismatchCounter = 0;
	int sc=0 ;

public:

	void Undo() override;
	void Redo() override;
	opStartGame(controller* pCont);
	virtual ~opStartGame();
	int score(int m, int mm);

	virtual void Execute();

};