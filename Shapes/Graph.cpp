#include "Graph.h"
#include "../GUI/GUI.h"
#include"Shape.h"

void Graph::Save(ofstream& savefile, string filename, string fcl, string drc, string pnw) {

	filename = filename + ".txt";
	savefile.open(filename);
	savefile << fcl << " " << drc << " " << pnw << endl;
	savefile << to_string(shapesList.size()) << endl;
	for (auto shapepp : shapesList) {

		savefile << shapepp->save(savefile, filename, fcl, drc, pnw) << endl;
	}


	savefile.close();
}
Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}
vector <shape*> Graph::GetHiddenlist() {
	return Hiddenshapes;
}
vector <shape*> Graph::Getshapeslist() {
	return shapesList;
}
void Graph::SetHiddenList(vector <shape*> shapeshidden, vector <color> colorhidden) {
	Hiddenshapes = shapeshidden;
	colorhiddens = colorhidden;
}
vector <color> Graph::Getcolorlist() {
	return colorhiddens;
}


void Graph::GetHidden(vector <shape*> Hiddenshapes, GUI* pUI) {
	for (auto Hidden : Hiddenshapes)
	{
		cout << "hi";
		Hidden->Draw(pUI);
	}
}

shape* Graph::GetSelected() {
	return selectedShape; 
}

void Graph::SetSelected(shape* sh) {
	selectedShape = sh;
}
shape* Graph::Getshape(Point p) const
{
	for (auto shapePointer : shapesList)
		if (shapePointer->IsINSHAPE(p)) {
			return shapePointer;
		}
	return nullptr;
}
void Graph::DeleteShape()
{
	int mycount = -1;
	for (auto selected : shapesList)
	{
		mycount++;
		if (selected->IsSelected())
		{
			shapesList.erase(shapesList.begin() + mycount);
			mycount--;
		}
	}
}
void Graph::Duplicatee(GUI* pUI)
{
	pUI->ClearDrawArea();
	for (auto shapepp : shapesList) {
		pUI->ClearDrawArea();
	//	shapepp->Duplicate(pUI);
	}
}

