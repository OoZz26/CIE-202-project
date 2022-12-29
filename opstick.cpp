#include ".\opStick.h"
#include "stick.h"
#include ".\controller.h"
#include ".\GUI\GUI.h"

opStick::opStick(controller* pCont):operation(pCont)
{}
opStick::~opStick()
{}

//Execute the operation
void opStick::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	Point p1 = { 400,400 };
	Point p2 = { 500,500 };
	Stick* st = new Stick(p1,p2);
	pGraph->Addshape(st);

}
