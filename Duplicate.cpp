#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "Duplicate.h"
#include "GUI/GUI.h"
#include <fstream>
opDuplicate::opDuplicate(controller* pCont) : operation(pCont) {}
opDuplicate :: ~opDuplicate() {}
void opDuplicate::DrawDuplicates(vector<shape*> duplicate, GUI* pUI, Graph* pGraph)
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

}

void opDuplicate::Undo()
{
}

void opDuplicate::Redo()
{
}

void opDuplicate::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	//shapelist = pGraph->getshapeslist();
	//DrawDuplicates(shapelist, pUI, pGraph);
	pGraph->Duplicate(pUI);
	pUI->PrintMessage("Shapes Duplicated");

}