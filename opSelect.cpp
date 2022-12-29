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
	//Read the point ti check it.
	pUI->GetPointClicked(P1.x, P1.y);
	shape* s = pGraph->Getshape(P1);
	if (s) {
		if (s->IsSelected() == false) {
			s->SetSelected(true);
			pGraph->SetSelected(s);
		}
		else {
			s->SetSelected(false);
			pGraph->SetSelected(nullptr);


		}
	}
	//else {
	//	s->SetSelected(true);
	//	pGraph->SetSelected(s);

}
	
	//if (s) {
	//	if (pGraph->GetSelected()) {
	//		s->SetSelected(true);

	//		if (s = pGraph->GetSelected()) {
	//			pGraph->GetSelected()->SetSelected(false);
	//			pGraph->SetSelected(s);

	//		}
	//		else {
	//			pGraph->GetSelected()->SetSelected(true);
	//			pGraph->SetSelected(s);

	//		}


	//	}

	//	else {
	//		s->SetSelected(true);
	//		pGraph->SetSelected(s);

	//	}
	//}


