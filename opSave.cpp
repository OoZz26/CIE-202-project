#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "opSave.h"
#include "GUI/GUI.h"
#include <fstream>
opSave::opSave(controller* pCont) : operation(pCont) {}
opSave :: ~opSave() {}


void opSave::Execute() {
	ofstream savefile;
	GUI* pUI = pControl->GetUI();
	color f = pUI->getCrntFillColor();
	string fcl = pControl->colortostring(f);
	color d = pUI->getCrntDrawColor();
	string drc = pControl->colortostring(d);
	string pnw = to_string(pUI->getCrntPenWidth());
	pUI->PrintMessage("Enter the file name: ");
	string filename = pUI->GetSrting();
	filename = filename + ".txt";
	pUI->ClearStatusBar();
	Graph* pGraph = pControl->getGraph();
	pGraph->Save(savefile, filename, fcl, drc, pnw);
	pUI->PrintMessage("File Saved");
}