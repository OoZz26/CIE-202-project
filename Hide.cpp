#include "Hide.h"
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
void opHide::Addhiddenshape(shape* hshape,color n)
{
	Hiddenshapes.push_back(hshape);
	//colorhidden.push_back(n);
}
opHide::opHide(controller* pCont) : operation(pCont) {}
opHide :: ~opHide() {}

void opHide::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	if (pGraph->GetSelected() != nullptr)
	{
		pUI->PrintMessage("Choose the shape you want to HIDE");
		Addhiddenshape(pGraph->GetSelected(),BLUE);
		//for (int i = 0; i < Hiddenshapes.size(); i++) {
			//cout << Hiddenshapes[i]->ID << endl;
		//}
		pGraph->SetHiddenList(Hiddenshapes, colorhidden);
		pGraph->GetSelected()->disappear();
		pUI->PrintMessage("Shapes Hidden");
	}

	else if (pGraph->GetSelected() == nullptr)
	{
		pUI->PrintMessage("YOU DID NOT SELECT A SHAPE ");


	}

}
