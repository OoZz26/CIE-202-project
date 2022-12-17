#pragma once


#include<iostream>
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};




class GUI
{
public:
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
private:
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_CIRC,		//Circle icon in menu

		//TODO: Add more icons names here
		ICON_Tri,
		ICON_Line,
		ICON_SQU,
		ICON_OVAL,
		ICON_Regularpolygon,
		ICON_IRRegularpolygon,
		ICON_SELECT,
		ICON_PEN,
		ICON_Border,
		ICON_Fill,
		ICON_Draw,
		ICON_EXIT,		//Exit icon
		DRAW_ICON_COUNT,		//no. of menu icons ==> This should be the last line in this enum

	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here

		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		StatusBarWidth,
		MenuIconWidth;		//Width of each icon in toolbar menu
	string message;
	bool Isfilled;



	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color StatusBarRedPa;//colors of color palette displayed in the status bar
	color StatusBarBluePa;
	color StatusBarBlackPa;
	color StatusBarYellowPa;
	color StatusBarGreenPa;
	int PenWidth;			//width of the pen that draws shapes
	bool isfilled;


	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	color CreateColorPalette();
	void CreateStatusBarRedPa() const;	//color displayed on status bar
	void CreateStatusBarBluePa() const;	//color displayed on status bar
	void CreateStatusBarBlackPa() const;	//color displayed on status bar
	void CreateStatusBarYellowPa() const;	//color displayed on status bar
	void CreateStatusBarGreenPa() const;	//color displayed on status bar

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawTri(Point P1, Point P2,Point P3, GfxInfo TriGfxInfo) const;  //Draw a Trinangle
	void DrawL(Point P1, Point P2, GfxInfo LGfxInfo) const;  //Draw a Line
	void DrawSQU(Point P1, int lenght ,GfxInfo SGfxInfo) const;  //Draw a Square
	void DrawOVAL(Point P1, Point P2, GfxInfo EGfxInfo) const;  //Draw a Ellipse
	void DrawCircle(Point P1, int raduis, GfxInfo CGfxInfo) const;  //Draw a circle
	void DrawRPolygon(int* arrx, int* arrY, int nvertices, GfxInfo RPolygonGfxInfo) const;  //Draw a Regular Polygon
	void IrRegularPolygon(int* arrx, int* arry, int nvertices, GfxInfo IrRPolygonGfxInfo) const;


	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor();	//get current drwawing color
	color setGeneralDrawColor(color col); // set a drawing color
	color getCrntFillColor() const;	//get current filling color
	color setGeneralFillColor(color col); // set a fill color
	int getCrntPenWidth() const;		//get current pen width
	void setCrntPenWidth(int Pen);
	bool getFillSt()const;
	bool getIsFilled();



	~GUI();
};

