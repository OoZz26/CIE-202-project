#include "Graph.h"
#include "../GUI/GUI.h"
// AHMED ABDELSTAR WORK.....
void Graph::Save(ofstream& outfile) {
	//Assuming there is a Save Button
	//After pressing the Button SAVE it will call this function and this function will use shapeslist which is a dynamic array that contains all drawn shapes to save all shapes into one file just after saving the parameters of each shape Separately 
	cout << "Save the file with the name: ";
	string filename;
	cin >> filename;
	filename = filename + ".txt";

	outfile.open(filename);
	outfile.close();
	for (int i = 0; i < shapesList.size(); i++) {
		outfile << shapesList[i];
	}
}
void Graph::load(ifstream& Infile) {
	cout << "Enter the file name : ";
	string filename;
	cin >> filename;
	filename = filename + ".txt";
	Infile.open(filename);
	if (!Infile) {
		cout << "Error: file could not be opened" << endl;
		exit(1);
	}
	for (int i = 0; i < shapesList.size(); i++) {
	/*	Infile >> shapesList[i];*/
	}
	Infile.close();
	// using Draw(GUI * pUI) const to draw all the shapes saved to the file 
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