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


Point P;
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
	vector<shape*> shapes = pGraph->GetCopied();
	for (auto shapeToPaste : shapes)
	{
		Rect* Rectan = dynamic_cast<Rect*>(shapeToPaste);
		Triangle* Tria = dynamic_cast<Triangle*>(shapeToPaste);
		Circle* Cir = dynamic_cast<Circle*>(shapeToPaste);
		Line* line = dynamic_cast<Line*>(shapeToPaste);
		Oval* oval = dynamic_cast<Oval*>(shapeToPaste);
		Square* Squ = dynamic_cast<Square*>(shapeToPaste);
		RegularPolygon* Regular = dynamic_cast<RegularPolygon*>(shapeToPaste);
		IrRegularPolygon* IrRegular = dynamic_cast<IrRegularPolygon*>(shapeToPaste);
		Point Po1,Po2,RefP;
		if (Rectan != NULL)
		{
			Po1 = Rectan->getP1();
			Po2 = Rectan->getP2();
			RefP.x = (Po1.x+Po2.x)/2;
			RefP.y = (Po1.y + Po2.y) / 2;
			Point diff = { RefP.x - Po2.x,RefP.y - Po2.y };
			Point NewP2 = { P.x - diff.x,P.y - diff.y };
			Point Diff2 = { P.x - Po2.x, P.y - Po2.y };
			Point NewP1 = { Po1.x + Diff2.x - diff.x,Po1.y + Diff2.y - diff.y };
			GfxInfo PastingShapeInfo = Rectan->GetGfxInfo();
			Rect* R = new Rect(NewP2, NewP1, PastingShapeInfo);
			pGraph->Addshape(R);
		}
	/*	if (Squ != NULL)
		{
			Po1 = Squ->getP1();
			Po2 = Squ->getP2();
			RefP = { ((Po1.x + Po2.x) / 2), ((Po1.y + Po2.y) / 2) };
			Point diff = { RefP.x - Po2.x,RefP.y - Po2.y };
			Point NewP2 = { P.x - diff.x,P.y - diff.y };
			Point Diff2 = { P.x - Po2.x, P.y - Po2.y };
			Point NewP1 = { Po1.x + Diff2.x - diff.x,Po1.y + Diff2.y - diff.y };
			GfxInfo PastingShapeInfo = Squ->GetGfxInfo();
			Square* Sq = new Square(NewP2, NewP1, PastingShapeInfo);
			pGraph->Addshape(Sq);
		}*/
		//if (Tria != NULL)
		//{
		//	Po1 = Tria->GetCorner1();
		//	Po2 = Tria->GetCorner2();
		//	Point Po3 = Tria->GetCorner3();
		///*	RefP.x = (Po1.x + Po2.x + Po3.x) / 3;
		//	RefP.y = (Po1.y + Po2.y + Po3.x) / 3;
		//	Point diff = { RefP.x - Po3.x,RefP.y - Po3.y };
		//	Point Diff2 = { P.x - Po3.x, P.y - Po3.y };*/
		//	Point NewP2 = { Po2.x + P.x,Po2.y +P.y};
		//	Point NewP3 = { Po3.x + P.x,Po3.y + P.y };
		//	Point NewP1 = { Po1.x + P.x,Po1.y + P.y };
		//	/*Point NewP3 = { Po2.x + Diff2.x - diff.x,Po2.y + Diff2.y - diff.y };
		//	Point NewP1 = { Po1.x + Diff2.x - diff.x,Po1.y + Diff2.y - diff.y };*/
		//	GfxInfo PastingShapeInfo = Tria->GetGfxInfo();
		//	Triangle* Tri = new Triangle (NewP1, NewP2,NewP3, PastingShapeInfo);
		//	pGraph->Addshape(Tri);
		//}
		if (Cir != NULL) {
				
			RefP = Cir->GetCenter();
			Point center = Cir->GetCenter();
			int distance = Cir->GetDistance();
			GfxInfo inf = Cir->GetGfxInfo();
			Point diff = { RefP.x - center.x,RefP.y - center.y };
			Point Ncenter = { (P.x - diff.x), (P.y - diff.y) };
			Point Nradius = { Ncenter.x + distance,Ncenter.y };
			Circle* C = new Circle(Ncenter, Nradius, inf);
			pGraph->Addshape(C);
		}
		if (line != NULL) 
		{
			
			Po1 = line->GetStart();
			Po2 = line->GetEnd(); 
			RefP = { ((Po1.x + Po2.x) / 2), ((Po1.y + Po2.y) / 2) };
			Point diff = { RefP.x - Po1.x,RefP.y - Po1.y };
			Point newP2 = { P.x - diff.x,P.y - diff.y };
			Point Diff2 = { P.x - Po1.x, P.y - Po1.y };
			Point newP1 = { Po2.x + Diff2.x - diff.x,Po2.y + Diff2.y - diff.y };
			GfxInfo inf = line->GetGfxInfo();
			Line* l = new Line(newP2, newP1, inf);
			pGraph->Addshape(l);
		}
		//if (oval != NULL) {

		//	RefP = oval->getP1();
		//	Point center = oval->getP1();
		//	//Point point2 = oval->getP2();
		//	int distance = oval->GetDistance();
		//	GfxInfo inf = oval->GetGfxInfo();
		//	Point diff = { RefP.x - center.x,RefP.y - center.y };
		//	Point Ncenter = { (P.x - diff.x), (P.y - diff.y) };
		//	Point Nradius = { Ncenter.x + distance,Ncenter.y };
		//	Oval* o = new Oval(Ncenter, Nradius, inf);
		//	pGraph->Addshape(o);
		//}
	
	}

}