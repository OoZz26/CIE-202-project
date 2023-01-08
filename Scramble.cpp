#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "Scramble.h"
#include "GUI/GUI.h"
opScramble::opScramble(controller* pCont) : operation(pCont) {}
opScramble :: ~opScramble() {}

void opScramble::DrawScramble(vector<shape*> duplicate, GUI * pUI, Graph * pGraph)
	{
		//cout << duplicate.size()<< endl;
		//dupl->ChngDrawClr(YELLOW);
		//dupl->Duplicate(pUI);
		//pUI->ClearDrawArea();
		pGraph = pControl->getGraph();
		cout << duplicate.size() << endl;
		for (auto shapePointer : duplicate) {
			shapePointer->setscrambled();
			shapePointer->Draw(pUI);
			shapePointer->setnotscrambled();
			//shapePointer->Duplicate(pUI);
			//pGraph->Addshape(shapePointer);
		}

	}

void opScramble::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	//shlist = pGraph->getshapeslist();
	//DrawScramble(shlist, pUI, pGraph);
	pUI->PrintMessage("Shapes scrambled");
	pGraph->scramble(pUI);
}