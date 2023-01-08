#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "Move.h"
#include "GUI/GUI.h"
#include <fstream>
opMove::opMove(controller* pCont) : operation(pCont) {}
opMove :: ~opMove() {}
void opMove::Execute() {
	Point P;
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	//shapelist = pGraph->getshapeslist();
	window* pWind = pUI->GetpWind();
	//DrawDuplicates(shapelist, pUI, pGraph);
	
	while (pWind->GetButtonState(LEFT_BUTTON, P.x, P.y) != BUTTON_DOWN)
	{
		if (pGraph->Getshape(P) != nullptr) {
			//shape* selectedshape = pGraph->Getshape(P);
			pGraph->Getshape(P)->Move(P.x, P.y);
			pUI->ClearDrawArea();
			pControl->UpdateInterface();
			Sleep(10);
		}

	}
}