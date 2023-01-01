#pragma once
#include "Shape.h"
#include<fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;
	shape* HiddenShape;	//pointer to the currently selected shape
	vector <shape*> Hiddenshapes;
	vector <color> colorhiddens;
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(Point p) const; //Search for a shape given a point inside the shape
	shape* GetSelected();
	void SetHiddenList(vector <shape*> shapeshidden, vector <color> colorhidden);
	vector<color> Getcolorlist();
	void SetSelected(shape* sh);
	bool setFilled(bool state);
	void GetHidden(vector <shape*> Hiddenshapes, GUI* pUI);
	vector <shape*> GetHiddenlist();
	vector<shape*> Getshapeslist();
	//void HideShape();
	virtual void Save(ofstream& savefile, string filename, string fcl, string drc, string pnw);		//Save all shapes to a file
	//void load(ifstream& inputfile);
	//Load all shapes from a file
	void DeleteShape();
	//void HideShape(GUI* pUI);
	virtual void Duplicatee(GUI* pUI);
	

};
