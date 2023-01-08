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
	vector <shape*> undoshapesList;
	vector <shape*> shapesList;
	vector <shape*> shapesList2;
	//a container to hold all shapes	
	vector <shape*> selectedshapes;
	shape* selectedShape;	//pointer to the currently selected shape
public:										
	Graph();
	~Graph();
	void popShapelist();
	shape* topundo();
	shape* getshapelist();
	void popundo();
	void popundoshaps();
	void pushundo(shape* sh);
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Addshape2(shape* pShp);
	void Addselectedshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	vector<shape*> getselectedshapes();
	vector<shape*> getlistshapes();
	shape* Getshape(Point p) const; //Search for a shape given a point inside the shape
	shape* GetSelected();
	void SetSelected(shape* sh);
	//bool setFilled(bool state);
	virtual void Save(ofstream& savefile, string filename, string fcl, string drc, string pnw);		//Save all shapes to a file
	//void load(ifstream& inputfile);
	//Load all shapes from a file
	void DeleteShape();
	void setCutShape();
	void setCopiedShape();
	vector <shape*> CopiedV;
	vector <shape*> GetCopied();

	void scramble(GUI* pUI);
	void scramble();
	void Duplicate(GUI* pUI);
	void Sendtoback(GUI* pUI);
	void Hide(GUI* pUI);
	void UnHide(GUI* pUI);
	//void Duplicate();

	vector<shape*> getshapeslist();

};
