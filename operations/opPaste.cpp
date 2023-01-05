#include "opPaste.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "..\shapes\Rect.h"
#include"..\Shapes\Shape.h"
#include "..\Triangle.h"
#include "..\Line.h"
#include "..\Circle.h"
#include"..\IrRegularPolygon.h"
#include"..\RegularPolygon.h"
#include "..\Square.h"
#include "..\Oval.h"

opPaste::opPaste(controller* pCont) :operation(pCont)
{}
opPaste::~opPaste()
{}
Point p;


void opPaste::ReadActionParameters() {
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Click On The Screen At A Point To Paste ");

	//Read 1 Center and store in point and Radius.
	pUI->GetPointClicked(P.x, P.y);
	pUI->ClearStatusBar();
}



// Execute the operation
// 

void opPaste::Execute()
{
	ReadActionParameters();
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	/*for (auto shapeToPaste : )
	{
		Point P;
		Rect* Rectan = dynamic_cast<Rect*>(shapeToPaste);
		Triangle* Tria = dynamic_cast<Triangle*>(shapeToPaste);
		Point RefP;
		if (Rectan != NULL)
		{
			RefP = Rectan->getP1();
			Point A = Rectan->getP1();
			Point B = Rectan->getP2();
			Point diff = { RefP.x - B.x,RefP.y - B.y };
			Point NewP2 = { P.x - diff.x,P.y - diff.y };
			Point diffdiff = { P.x - B.x, P.y - B.y };
			Point NewP1 = { A.x + diffdiff.x - diff.x,A.y + diffdiff.y - diff.y };
			GfxInfo PastingShapeInfo = Rectan->GetGfxInfo();
			Rect* R = new Rect(NewP2, NewP1, PastingShapeInfo);

		}
	}*/
}