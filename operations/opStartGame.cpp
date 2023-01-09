#include "opStartGame.h"
#include "../controller.h"
#include "../GUI/GUI.h"


void opStartGame::Undo()
{
}

void opStartGame::Redo()
{
}

opStartGame::opStartGame(controller* pCont) :operation(pCont)
{}
opStartGame::~opStartGame()
{}

int opStartGame::score(int m, int mm)
{
	m = matchCounter;
	mm = MismatchCounter;
	sc = m - mm;
	return sc;
}

//Execute the operation

void opStartGame::Execute()
{
	//GUI* pUI = pControl->GetUI();
	//Graph* pGraph = pControl->getGraph();
	//Point P1,P2;
	//pControl->getGraph()->Duplicate(pUI);
	//pControl->getGraph()->Hide(pUI);
	//pControl->getGraph()->scramble(pUI);
	//pUI->PrintMessage("CLICK AT THE FIRST SHAPE ");
	//pUI->GetPointClicked(P1.x, P1.y);
	//pControl->getGraph()->UnHide(&P1);
	//pControl->getGraph()->UnHide(pUI);
	//pUI->PrintMessage("CLICK AT THE SECOND SHAPE ");
	//pUI->GetPointClicked(P2.x, P2.y);
	//pControl->getGraph()->UnHide(&P2);
	//pControl->getGraph()->UnHide(pUI);
	////pGraph->setMatch(P1, P2); // send the points to match
	////pControl->getGraph()->Getshape();
	//if (pGraph->IsMatched(P1,P2) == true)
	//{
	//	matchCounter += 3;
	//	score(matchCounter, MismatchCounter);
	//	string msg = "NICE MATCH ! YOUR CURRENT SCORE IS : ( "+ to_string(sc) +" )";
	//	pUI->PrintMessage(msg);
	//}
	//else
	//{
	//	MismatchCounter += 1;
	//	score(matchCounter, MismatchCounter);
	//	string msg = "TRY AGAIN, YOUR CURRENT SCORE IS : ( " + to_string(sc) + " )";
	//	pControl->getGraph()->Hide(pUI);
	//	//shape* sh1 = pGraph->Getshape(P1);
	//	//shape* sh2 = pGraph->Getshape(P2);
	//	//pGraph->UnHide(sh1);
	//}
	//string msg = "CONGRATS, YOUR FINAL SCORE IS : ( " + to_string(sc) + " )";
	//pControl->getGraph()->Hide(pUI);
	//pUI->ClearStatusBar();

	
}