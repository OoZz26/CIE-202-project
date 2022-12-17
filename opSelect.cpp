#include "opSelect.h"



opSelect::opSelect(controller* pCont) :operation(pCont)
{}


opSelect::~opSelect()
{}

//Execute the operation
void opSelect::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Click on the Shape ");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	shape* s = pGraph->Getshape(P1);
	if (s) {
		if (pGraph-> GetSelected()) {
			s->SetSelected(true);
			pGraph->GetSelected()->SetSelected(false);
			pGraph->SetSelected(s);
		}
		else {
			s->SetSelected(true);
			pGraph->SetSelected(s);
		}
	}


}
