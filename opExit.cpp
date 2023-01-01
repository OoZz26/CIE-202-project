#include "opExit.h"
#include "controller.h"
#include"GUI/GUI.h"

opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit::~opExit()
{}

//Execute the operation
void opExit::Execute()
{
	string Exit;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Do you want to save Y/N");
	
	Exit = pUI->GetSrting();
	if (Exit == "Y" || Exit == "y") {
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
	else
		exit;


	Graph* pGr = pControl->getGraph();

	//Add the Circle to the list of shapes


}

