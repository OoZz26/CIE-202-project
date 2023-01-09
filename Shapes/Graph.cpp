#include "Graph.h"
#include "../GUI/GUI.h"
#include"Shape.h"
#include <algorithm>
#include<cstdlib>
#include<ctime>
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
void Graph::popShapelist()
{
	cout << shapesList.size()<<endl;
	undoshapesList.push_back(shapesList.back());
	
	cout << undoshapesList.back();
	cout << shapesList.back();

	shapesList.pop_back();
	cout << "ss" << endl;
	cout << shapesList.size() << endl;

	
}
void Graph::popundovector() {
	cout << "test" << endl;
	cout << undoshapesList.size() << endl;
	shapesList.push_back(undoshapesList.back());

	cout << undoshapesList.back()<<endl;
	cout << shapesList.back()<<endl;

	shapesList.pop_back();
	cout << "ss" << endl;
	cout << shapesList.size() << endl;

}
shape* Graph::getshapelist()
{
	return shapesList.back();
}
shape* Graph::topundo()
{
	return undoshapesList.back();
}

void Graph::popundo()
{
	undoshapesList.pop_back();

}

void Graph::popundoshaps()
{
	shapesList.push_back(undoshapesList.back());
	undoshapesList.pop_back();

}

void Graph::pushundo(shape* sh)
{
	undoshapesList.push_back(sh);
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
	//shapesList2.push_back(pShp);
	//shapesList2.push_back(pShp);
}
void Graph::Addshape2(shape* pShp)
{
	//Add a new shape to the shapes vector
	//shapesList2.push_back(pShp);
	//shapesList2.push_back(pShp);
	//shapesList2.push_back(pShp);
}


void Graph::Addselectedshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	selectedshapes.push_back(pShp);
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}
vector <shape*> Graph::getselectedshapes() {
	return selectedshapes;
}
vector <shape*> Graph::getlistshapes() {
	return shapesList;
}


shape* Graph::GetSelected() {
	return selectedShape; 
}

void Graph::SetSelected(shape* sh) {
	Addselectedshape(sh);
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



void Graph::setCopiedShape()
{
	//int shapeCount = -1;
	for (auto selectedSh : shapesList)
	{
		//shapeCount++;
		if (selectedSh->IsSelected())
		{
			CopiedV.push_back(selectedSh);
		}
	}
}

vector<shape*> Graph::GetCopied() {
	return CopiedV;

}
void Graph::Refresh() {
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList.clear();
	}
}
void Graph::Undo1() {
	//Refresh();
	//for (int i = 0; i < undoshapesList.size(); i++) {
	//	shapesList.push_back(redoshapesList[i]);

}

//void Graph::Undo1() {
//	Refresh();
//	for (int i = 0; i < undoshapesList.size(); i++) {
//		shapesList.push_back(redoshapesList[i]);
//
//}

void Graph::Redo1()
{
	//Refresh();
	//for (int i = 0; i < undoshapesList.size(); i++) {
	//	shapesList.push_back(redoshapesList[i]);
	//}
}



void Graph::setCutShape()
{
	setCopiedShape();
	//int shapeCount = -1;
	//int c = -1;
	//for (auto selected = shapesList.begin(); selected !=shapesList.end(); ++selected)
	//{
	//	
	//	//shapeCount++;
	//	if (( * selected)->IsSelected())
	//	{
	//		//shapesList.pop_back();
	//	/*	selectedshapes.erase(selectedshapes.begin() + c);*/
	//		shapesList.erase(selected);
	//		selected--;

	//	}
	//}
	//}
	// 
	//for (unsigned int i = 0; i < shapesList.size(); i++)
	//{
	//	//shapeCount++;
	//	if (shapesList[i]->IsSelected())
	//	{
	//		//if (selectedshapes[i] == shapesList[i])
	//			//i++;
	//			//shapesList.pop_back();
	//		shapesList.erase(shapesList.begin() + i);

	//	}
	//}



	//setCopiedShape();
	//int shapeCount = -1;
	//for (auto selected : selectedshapes)
	//{
	for (auto selected : shapesList)
	{
		//shapeCount++;
		if (selected->IsSelected())
		{
			shapesList.pop_back();

		}
	}
	//}
}

void Graph::scramble(GUI*pUI)
{
	srand(time(0));
	int dist1y = (rand() % 500);
	int dist1x = (rand() % 1000);
	for (int i = 0; i < shapesList.size(); i++) {
		pUI->ClearDrawArea();
		shapesList[i]->Move(dist1x,dist1y);
		
	}

}

void Graph::Duplicate(GUI* pUI)
{
	//cout << "Dupl";
	{
		//pUI->ClearDrawArea();
		/*for (auto shapePointer : shapesList)
		{
			shapePointer->Draw(pUI); 
		}*/

		for (int i = 0; i < shapesList2.size();i++) {
			//shapesList[j]->Draw(pUI);
			//shapesList2[i]->Duplicate(pUI);
			cout << "nnnn";
			Addshape(shapesList[i]);

		}
		
	}
	cout << shapesList.size();
}

void Graph::Sendtoback(GUI* pUI)
{
	if (GetSelected() == nullptr) {
		pUI->PrintMessage("CHOOSE a shape first ");
	}
	else if (GetSelected() != nullptr)
	{
		pUI->PrintMessage("CHOOSE the shape to send back : ");
		shape* temp = shapesList[0];
		shapesList[0] = GetSelected();
		for (int i = 0; i < shapesList.size(); i++) {
			if (shapesList[i] == GetSelected()) {
				shapesList[0] = GetSelected();
				shapesList[i] = temp;
				cout << "did we get here";
			}

		}
		for (auto shapePointer : shapesList) {
			shapePointer->Draw(pUI);
			cout << "hnnnnaaa";
		}
		
		pUI->ClearStatusBar();
	}

	else if (GetSelected() == nullptr)
	{
		pUI->PrintMessage("YOU DID NOT SELECT A SHAPE ");
		color col = pUI->getCrntFillColor();


	}
}

void Graph::Hide(GUI* pUI) {

	for (int i = 0; i < shapesList.size(); i++) {
		int x = shapesList[i]->Getshapeparameters()[0];
		int y = shapesList[i]->Getshapeparameters()[1];
		int width = shapesList[i]->Getshapeparameters()[2];
		int height = shapesList[i]->Getshapeparameters()[3];
		window* pWind = pUI->GetpWind();//point-(height,width
		shapesList[i]->ChngDrawClr(BLACK);
		pWind->DrawImage("images\\MenuIcons\\Menu_Card.jpg", x , y , width, height);
		cout << shapesList.size();
		//point-height,width

	}
}
void Graph::UnHide(GUI* pUI) {
	for (int i = 0; i < shapesList.size(); i++) {
		window* pWind = pUI->GetpWind();
		pUI->ClearDrawArea();
		shapesList[i]->Draw(pUI);
	}
}
void Graph::ZoomOpration(double zoomvalue) {
	for (int i = 0; i < shapesList.size(); i++)
		shapesList[i]->zoom(zoomvalue);
}
