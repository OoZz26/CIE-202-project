#pragma once

#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);

	virtual ~shape() {}
	double distance(int x1,int y1,int x2,int y2);
	double tri_area(Point p1, Point p2, Point p3 );
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	string colortostring(color c);
	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	int ChngBorderWidth(int BoWi); //changes the shape's border width
	virtual bool IsINSHAPE(Point test) = 0;
	virtual string save(ofstream& savefile, string filename, string fcl, string drc, string pnw);
	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the shape
	virtual void Resize(double factor) = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	//virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};

