#include "opCopy.h"
#include "../controller.h"
#include "../GUI/GUI.h"
opCopy::opCopy(controller* pCont) :operation(pCont)
{}
opCopy::~opCopy()
{}

shape* ShapeCopy;

//Execute the operation

void opCopy::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	if (pGraph->GetSelected() != nullptr) 
	{
		if (pControl->getShapeToCopy() != nullptr)
		{
			if (pControl->getShapeToCopy()->IsCutOr())
			{
				pControl->setUpdateCut(nullptr);
				pControl->getShapeToCopy()->setShapeCut(false);
			}

		}
		ShapeCopy = pGraph->GetSelected();
		pControl->setShapeToCopy(ShapeCopy);
		pUI->PrintMessage("THE SHAPE IS COPIED");
	}

	else if (pGraph->GetSelected() == nullptr)
	{
		pUI->PrintMessage("YOU DID NOT SELECT A SHAPE TO COPY");
	}

}
