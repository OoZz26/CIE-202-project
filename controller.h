#pragma once

#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"
#include<stack>

class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{

	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	shape* copiedShape;
	shape* updateCut;
	stack <operation*> OPerations;
	stack <operation*> Redo;
public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	string colortostring(color c); //Convert from Color Type to String Type
	color stringtocolor(string s);
	void Run();
	int countp();
	Graph* getGraph() const;
	operation* topOpetrations();
	operation* topREDO();
		
	void popOpeartion();
	void popRedo();
	int count();
	void setShapeToCopy(shape* CoShape);
	shape* getShapeToCopy();
	void setUpdateCut(shape* cutt);
	shape* getUpdateCut() const;

	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI
	void UpdateInterface() const;	//Redraws all the drawing window	

};

