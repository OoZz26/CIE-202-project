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

//int opStartGame::score()
//{
//	sc = matchCounter - MismatchCounter;
//}

//Execute the operation

void opStartGame::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	Point P1,P2;
	pControl->getGraph()->Duplicate(pUI);
	pControl->getGraph()->Hide(pUI);
	pControl->getGraph()->scramble(pUI);
	pUI->PrintMessage("CLICK AT THE FIRST SHAPE ");
	//pUI->GetPointClicked(P1.x, P1.y);
	//pUI->PrintMessage("CLICK AT THE SECOND SHAPE ");
	//pUI->GetPointClicked(P2.x, P2.y);
	//pGraph->setMatch(P1, P2); // send the points to match
	//pControl->getGraph()->Getshape();
	//if (pGraph->IsMatched() == true)
	//{
	//	matchCounter += 3;
	//	string msg = "NICE MATCH ! YOUR CURRENT SCORE IS : ( "+ to_string(sc) +" )";
	//	pUI->PrintMessage(msg);
	//}
	//else
	//	MismatchCounter += 1;
	//	string msg = "TRY AGAIN, YOUR CURRENT SCORE IS : ( " + to_string(sc) + " )";
	//	shape* sh1 = pGraph->Getshape(P1);
	//	shape* sh2 = pGraph->Getshape(P2);
	//	//pGraph->UnHide(sh1);

	//pUI->ClearStatusBar();

	
}