#include "Unhide.h"
#include"Hide.h"
#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "GUI/GUI.h"
#include"Shapes/Graph.h"
#include "Oval.h"
#include "Circle.h"
#include "Triangle.h"
#include"controller.h"
#include"operations/operation.h"
#include"GUI/GUI.h"
#include"Shapes/Shape.h"
void opUnhide::DrawHidden(vector<shape*> hidden,vector <color> colorhiddenn, GUI* pUI)
{
	for (int i = 0; i < hidden.size();i++) {
	
			hidden[i]->appear();
			//hidden[i]->ChngDrawClr(colorhiddenn[i]);
			hidden[i]->Draw(pUI);

			//shapePointer->appear();
			//shapePointer->ChngDrawClr(YELLOW);
			//shapePointer->Draw(pUI);
			//cout << "Hereeeeee" << endl;
			//cout << "UNHIDE" << shapePointer->ID+1;
			//cout<< shapePointer.
	}
}

opUnhide::opUnhide(controller* pCont) : operation(pCont) {}
opUnhide :: ~opUnhide() {}
void opUnhide::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	Hiddenshapes2 = pGraph->GetHiddenlist();
	colorhidden2 = pGraph->Getcolorlist();

	
	//pGraph->GetHidden(Hiddenshapes2, pUI);
	DrawHidden(Hiddenshapes2 ,colorhidden2, pUI);
	pUI->PrintMessage("Shapes UnHidden");
}