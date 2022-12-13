#include "Graph.h"
#include "../GUI/GUI.h"
// AHMED ABDELSTAR WORK.....

Graph::Graph()
{
	selectedShape = nullptr;
}
void Graph::Save(ofstream& savefile) {

	/*GUI* pUI = ;

	pUI->PrintMessage("Enter the file name: ");

	string filename = pUI->GetSrting();*/

	string filename = "filename.txt";

	savefile.open(filename);

	for ( auto shapepointer : shapesList ) {
		savefile << shapepointer->save(savefile);
	}
	

	savefile.close();
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


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}
