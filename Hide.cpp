#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "hide.h"
#include "GUI/GUI.h"
#include <fstream>
opHide::opHide(controller* pCont) : operation(pCont) {}
opHide :: ~opHide() {}
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

void opHide::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	//shapelist = pGraph->getshapeslist();
	//DrawDuplicates(shapelist, pUI, pGraph);
	pGraph->Hide(pUI);
	pUI->PrintMessage("Shapes Hidden");

}