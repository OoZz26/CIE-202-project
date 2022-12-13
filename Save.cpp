#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "Save.h"
#include "GUI/GUI.h"
#include <fstream>
opSave::opSave(controller* pCont) : operation (pCont) {}
opSave :: ~opSave(){}
void opSave::Execute() {
	ofstream savefile;
	Graph* pGraph = pControl->getGraph();
	pGraph->Save(savefile);
}