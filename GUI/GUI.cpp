#include "GUI.h"


GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 650;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	StatusBarWidth = 1000;
	ToolBarHeight = 50;
	MenuIconWidth = 50;

	DrawColor = BLUE;	//default Drawing color
	FillColor = SKYBLUE;	//default Filling color
	MsgColor = WHITE;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = BLACK;
	StatusBarWhitePa = WHITE; //colors of color palette displayed in the status bar
	StatusBarRedPa = RED; 
	StatusBarBluePa = BLUE;
	StatusBarBlackPa = BLACK;
	StatusBarYellowPa = YELLOW;
	StatusBarGreenPa = GREEN;
	PenWidth = 3;	//default width of the shapes frames
	message = "COLOR PALETTE";
	Isfilled = false;


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
	CreateStatusBarWhitePa();
	CreateStatusBarRedPa();
	CreateStatusBarBluePa();
	CreateStatusBarBlackPa();
	CreateStatusBarYellowPa();
	CreateStatusBarGreenPa();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_EXIT: return EXIT;
			case ICON_Tri: return DRAW_TRI; 
			case ICON_Line: return DRAW_LINE;
			case ICON_SQU: return DRAW_SQU;
			case ICON_OVAL: return DRAW_OVAL;
			case ICON_IRRegularpolygon: return DRAW_IRRPOLYGON;
			case ICON_Regularpolygon: return DRAW_RPOLYGON;
			case ICON_PEN: return PEN_WIDTH;
			case ICON_Border: return BORDER_WIDTH;
			case ICON_BALETTE: return COLOR_PALETTE;
			case ICON_SELECT: return SELECT;
			case ICON_Fill: return FILL_COLOR;
			case ICON_Draw: return DRAW_COLOR;
			case ICON_Copy: return COPY;
			case ICON_SAVE: return SAVE;
			case ICON_LOAD: return LOAD;
			case ICON_DELETE:return DEL;
			case ICON_RESIZE:return RESIZE;
			case ICON_PLAY: return TO_PLAY;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{

		if (y >= 0 && y < ToolBarHeight)
		{

			int ClickedIconOrder = (x / MenuIconWidth);


			switch (ClickedIconOrder)
			{
			case ICON_DRAW: return TO_DRAW;
			case DRAW_ICON_COUNT: return TO_DRAW;


			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return TO_PLAY;	//just for now. This should be updated
	}

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, StatusBarWidth, height);// main status bar rectangle

}


color GUI::CreateColorPalette()
{
	color COL;
	int x, y;
	pWind->WaitMouseClick(x, y);
	if ((y > height - StatusBarHeight) && (y < height))
	{
		if ((x > StatusBarWidth) && (x < StatusBarWidth + 45))
		{
			COL = WHITE;
		}
		else if ((x > StatusBarWidth+45) && (x < StatusBarWidth + 90))
		{
			COL = RED;
		}
		else if ((x > StatusBarWidth + 90) && (x < StatusBarWidth + 135))
		{
			COL = BLUE;
		}
		else if ((x > StatusBarWidth + 135) && (x < StatusBarWidth + 180))
		{
			COL = BLACK;
		}
		else if ((x > StatusBarWidth + 180) && (x < StatusBarWidth + 225))
		{
			COL = YELLOW;
		}
		else if ((x > StatusBarWidth + 225) && (x < width))
		{
			COL = GREEN;
		}
	}
	return COL;
}

void GUI::CreateStatusBarWhitePa() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(StatusBarWhitePa);
	pWind->DrawRectangle(StatusBarWidth, height - StatusBarHeight, StatusBarWidth + 45, height);
	pWind->DrawLine(0, StatusBarHeight, width, StatusBarHeight);
}

void GUI::CreateStatusBarRedPa() const
{
	pWind->SetBrush(StatusBarRedPa);
	pWind->DrawRectangle(StatusBarWidth + 45, height - StatusBarHeight, StatusBarWidth + 90, height);
}
void GUI::CreateStatusBarBluePa() const
{
	pWind->SetBrush(StatusBarBluePa);
	pWind->DrawRectangle(StatusBarWidth + 90, height - StatusBarHeight, StatusBarWidth + 135, height);
}
void GUI::CreateStatusBarBlackPa() const
{
	pWind->SetBrush(StatusBarBlackPa);
	pWind->DrawRectangle(StatusBarWidth + 135, height - StatusBarHeight, StatusBarWidth + 180, height);
}
void GUI::CreateStatusBarYellowPa() const
{
	pWind->SetBrush(StatusBarYellowPa);
	pWind->DrawRectangle(StatusBarWidth + 180, height - StatusBarHeight, StatusBarWidth + 225, height);
}
void GUI::CreateStatusBarGreenPa() const
{
	pWind->SetBrush(StatusBarGreenPa);
	pWind->DrawRectangle(StatusBarWidth + 225, height - StatusBarHeight, width, height);
}


//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, StatusBarWidth, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() {

pWind->SetPen(BkGrndColor, 1);
pWind->SetBrush(BkGrndColor);
pWind->DrawRectangle(0, 0, width, ToolBarHeight); 
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_Tri] = "images\\MenuIcons\\Menu_Tri.jpg";
	MenuIconImages[ICON_Line] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_SQU] = "images\\MenuIcons\\Menu_Square.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\Menu_OVAL.jpg";
	MenuIconImages[ICON_Regularpolygon] = "images\\MenuIcons\\Menu_Regularpolygon.jpg";
	MenuIconImages[ICON_IRRegularpolygon] = "images\\MenuIcons\\Menu_IRRegular.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\Menu_Select.jpg";
	MenuIconImages[ICON_BALETTE] = "images\\MenuIcons\\Menu_Palette.jpg";
	MenuIconImages[ICON_PEN] = "images\\MenuIcons\\Menu_PEN.jpg";
	MenuIconImages[ICON_Border] = "images\\MenuIcons\\Menu_Border.jpg";
	MenuIconImages[ICON_Fill] = "images\\MenuIcons\\Menu_Fill.jpg";
	MenuIconImages[ICON_Draw] = "images\\MenuIcons\\Menu_Draw.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\Menu_Delete.jpg";
	MenuIconImages[ICON_RESIZE] = "images\\MenuIcons\\Menu_Resize.jpg";
	MenuIconImages[ICON_Copy] = "images\\MenuIcons\\Menu_Copy.jpg";
	MenuIconImages[ICON_PLAY] = "images\\MenuIcons\\menu_Play_Mode.jpg";
	//TODO: Prepare images for each menu icon and add it to the list
	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////


void GUI::CreatePlayToolBar()
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);
	InterfaceMode = MODE_PLAY;

	string PLAYMenuIconImages[PLAY_ICON_COUNT];
	PLAYMenuIconImages[ICON_DRAW] = "images\\MenuIcons\\menu_draw_Mode.jpg";
	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(PLAYMenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() 	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::setGeneralDrawColor(color col) // set a drawing color
{
	DrawColor = col;
	return 0;
}

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}

color GUI::setGeneralFillColor(color col) // set a filling color
{
	//Isfilled = true;
	FillColor = col;
	return 	FillColor;

}
//////////////////////////////////////////////////////////////////////////////////////////
bool GUI::getIsFilled()
{
	Isfilled = true;
	return Isfilled;
}
int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}
void GUI::setCrntPenWidth(int Pen)
{
	PenWidth = Pen;
}
bool GUI::getFillSt()const
{
	return Isfilled;
}


//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void GUI::DrawTri(Point P1, Point P2,Point P3, GfxInfo TriGfxInfo) const
{
	color DrawingClr;
	if (TriGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y,P3.x,P3.y, style);

}


void GUI::DrawL(Point P1, Point P2,GfxInfo LGfxInfo) const
{
	color DrawingClr;
	if (LGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}
void GUI::DrawSQU(int* arrx, int* arrY, int nvertices, GfxInfo SQUGfxInfo)  const
{
	{
		color DrawingClr;
		if (SQUGfxInfo.isSelected)	//shape is selected
			DrawingClr = HighlightColor; //shape should be drawn highlighted
		else
			DrawingClr = SQUGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, SQUGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (SQUGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(SQUGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawPolygon(arrx, arrY, nvertices, style);

	}
}
void GUI::DrawOVAL(Point P1, Point P2, GfxInfo OVALGfxInfo) const
{
	color DrawingClr;
	if (OVALGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OVALGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OVALGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (OVALGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OVALGfxInfo.FillClr);
	}
	else
		style = FRAME;
	//erorr no Draw Oval in smugraphics
	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}

void GUI::DrawCircle(Point P1, int  raduis, GfxInfo CGfxInfo) const
{
	color DrawingClr;
	if (CGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y,raduis ,style);
}


void GUI::DrawRPolygon(int* arrx, int* arrY, int nvertices, GfxInfo RPolygonGfxInfo) const
{
	color DrawingClr;
	if (RPolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RPolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RPolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RPolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RPolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(arrx, arrY, nvertices, style);

}
void GUI::IrRegularPolygon(int* arrx, int* arry, int nvertices, GfxInfo IrRPolygonGfxInfo) const
{
	color DrawingClr;
	if (IrRPolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = IrRPolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, IrRPolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (IrRPolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(IrRPolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(arrx, arry, nvertices, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

