#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "Unhide.h"
#include "GUI/GUI.h"
#include <fstream>
opUnhide::opUnhide(controller* pCont) : operation(pCont) {}
opUnhide :: ~opUnhide() {}
/*void opHide::DrawDuplicates(vector<shape*> duplicate, GUI* pUI, Graph* pGraph)
{
	//cout << duplicate.size()<< endl;
	//dupl->ChngDrawClr(YELLOW);
	//dupl->Duplicate(pUI);
	//pUI->ClearDrawArea();
	pGraph = pControl->getGraph();
	cout << duplicate.size() << endl;
	for (auto shapePointer : duplicate) {
		shapePointer->setduplicate();
		shapePointer->Draw(pUI);
		pGraph->Addshape(shapePointer);
	}

}*/

void opUnhide::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	//shapelist = pGraph->getshapeslist();
	//DrawDuplicates(shapelist, pUI, pGraph);
	pGraph->UnHide(pUI);
	pUI->PrintMessage("Shapes Hidden");

}