#include"Shapes/Shape.h"
#include "operations/opAddRect.h"
#include "Shapes/Rect.h"
#include "controller.h"
#include "opLoad.h"
#include "GUI/GUI.h"
#include <fstream>
#include "Line.h"
#include"Triangle.h"
#include"Circle.h"
#include"Square.h"
#include"RegularPolygon.h"
#include <corecrt_math_defines.h>
#include <cmath>
double opLoad::distance(int x1, int y1, int x2, int y2) {
	double distance;
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return distance;
}
opLoad::opLoad(controller* pCont) : operation(pCont) {}
opLoad :: ~opLoad() {}
void opLoad::Execute() {
	ifstream loadfile;
	string filename, shpname, DrawClr, FillClor, penw, shpc;
	int Count;
	shape* shp;
	int ID, dis;
	Point X, Y, Z ;
	Point* P = new Point ;
	string color1, color2;
	GfxInfo Info;
	int* arrx = new int ;
	int* arrY = new int;
	int* arrz = new int;
	int* arrm = new int;
	int nvertices; 
	GUI* pUI = pControl->GetUI();
	pUI->ClearDrawArea();
	pUI->PrintMessage("Enter the name of the file to be loaded: ");
	filename = pUI->GetSrting();     //get the file name
	loadfile.open(filename);//open the file on the disk with FileName name and .txt exetension
	while (loadfile.fail()) {
		cout << "fail";
		pUI->PrintMessage("Wrong name , Please enter a VALID name: ");
		filename = pUI->GetSrting();
	}
	loadfile >> DrawClr >> FillClor >> penw;
	//loadfile >> shpc;
	cout << "\n" << DrawClr << FillClor << penw; //Read the Current FillColor and DrawColor
	loadfile >> shpc;
	Count = stoi(shpc);//string to int
	color d = pControl->stringtocolor(DrawClr);
	color f = pControl->stringtocolor(FillClor);

	Info.BorderWdth = 2;
	cout << "\n did we get here?";
	for (int i = 0; i < Count; i++) {
		cout << "Here??";
		loadfile >> shpname;
		if (shpname == "Rectangle") {
			//"Rectangle " + to_string(ID) + " " + to_string(Corner1.x) + " " + to_string(Corner1.y) + " " + to_string(Corner2.x) + " " + to_string(Corner2.y) + " " + x + " " + y;
			loadfile >> X.x >> X.y >> Y.x >> Y.y >> color1 >> color2;
			color c1 = pControl->stringtocolor(color1);
			Info.DrawClr = c1;
			if (color2 != "NO_FILL") {
				color c2 = pControl->stringtocolor(color2);
				Info.FillClr = c2;
				Info.isFilled = true;
			}
			else {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}

			shp = new Rect(X, Y, Info);
			pUI->DrawRect(X, Y, Info);
			Graph* pGr = pControl->getGraph();
			pGr->Addshape(shp);
		}

		else if (shpname == "Line") {
			loadfile >> (X.x) >> X.y >> Y.x >> Y.y >> color1 >> color2;
			cout << X.x << X.y << Y.x << Y.y;

			color c1 = pControl->stringtocolor(color1);
			Info.DrawClr = c1;
			Info.isFilled = false;
			shp = new Line(X, Y, Info);
			pUI->DrawL(X, Y, Info);
			Graph* pGr = pControl->getGraph();
			pGr->Addshape(shp);
		}


		else if (shpname == "Triangle") {
			loadfile >> X.x >> X.y >> Y.x >> Y.y >> Z.x >> Z.y >> color1 >> color2;
			color c1 = pControl->stringtocolor(color1);
			Info.DrawClr = c1;
			if (color2 != "NO_FILL") {
				color c2 = pControl->stringtocolor(color2);
				Info.FillClr = c2;
				Info.isFilled = true;
			}
			else {
				Info.isFilled = false;
				Info.FillClr = WHITE;
			}
			shp = new Triangle(X, Y, Z, Info);
			pUI->DrawTri(X, Y, Z, Info);
			Graph* pGr = pControl->getGraph();
			pGr->Addshape(shp);
		}
		else if (shpname == "Circle") {
			//"Circle " + to_string(ID) + " " + to_string(Center.x) + " " + to_string(Center.y) + " " + to_string(Distance) +  " " + x + " " + y;
			loadfile >> X.x >> X.y >> Y.x >> Y.y >> dis >> color1 >> color2;
			color c1 = pControl->stringtocolor(color1);
			Info.DrawClr = c1;
			if (color2 != "NO_FILL") {
				color c2 = pControl->stringtocolor(color2);
				Info.FillClr = c2;
				Info.isFilled = true;
			}
			else {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			//string info = "Circle " + to_string(Center.x) + " " + to_string(Center.y) + " " + to_string(Raduis.x)+ " " +to_string(Raduis.y) + " " + to_string(Distance) + " " + x + " " + y;
			shp = new Circle(X, Y, Info);
			pUI->DrawCircle(X, dis, Info);
			Graph* pGr = pControl->getGraph();
			pGr->Addshape(shp);
		}
		//else if (shpname == "Square") {

		//	loadfile >> X.x >> X.y >> Y.x >> Y.y >> dis >> color1 >> color2;
		//	color c1 = pControl->stringtocolor(color1);
		//	Info.DrawClr = c1;
		//	if (color2 != "NO_FILL") {
		//		color c2 = pControl->stringtocolor(color2);
		//		Info.FillClr = c2;
		//		Info.isFilled = true;
		//	}
		//	else {
		//		Info.isFilled = false;
		//		Info.FillClr = NULL;
		//	}
		//	shp = new Square(X, Y, Info);
		//	pUI->DrawSQU(X, dis, Info);
		//	Graph* pGr = pControl->getGraph();
		//	pGr->Addshape(shp);
		//}
		else if (shpname == "Oval") {

			loadfile >> X.x >> X.y >> Y.x >> Y.y >> color1 >> color2;
			color c1 = pControl->stringtocolor(color1);
			Info.DrawClr = c1;
			if (color2 != "NO_FILL") {
				color c2 = pControl->stringtocolor(color2);
				Info.FillClr = c2;
				Info.isFilled = true;
			}
			else {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			//string info = "Oval " + to_string(P1.x) + " " + to_string(P1.y) + " " + to_string(P2.x) + " " + to_string(P2.y) + " " + x + " " + y;
            //shp = new OVAL()
			pUI->DrawOVAL(X, Y , Info);
		}

		else if (shpname == "IrRegularPolygon") {
			//string info = "IrRegularPolygon " + to_string(Point1->x) + " " + to_string(Point1->y) + " " + to_string(Vertices_num) + " " + x + " " + y;
			loadfile >> P->x >> P->y >> dis >> color1 >> color2;
			for (int i = 0; i < dis; i++) {
				arrx[i] = P[i].x;
				arrY[i] = P[i].y;
			}
			color c1 = pControl->stringtocolor(color1);
			Info.DrawClr = c1;
			if (color2 != "NO_FILL") {
				color c2 = pControl->stringtocolor(color2);
				Info.FillClr = c2;
				Info.isFilled = true;
			}
			else {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			pUI->DrawRPolygon(arrx, arrY, dis, Info);
		}
		else if (shpname == "RegularPolygon") {

			loadfile >> X.x >> X.y >> P->x >> P->y >> dis >> color1 >> color2;
			for (int i = 0; i < dis; i++) {
				int radius = distance(X.x, X.y, P->x, P->y);
				int vertixx = X.x + radius * cos(i * 2 * M_PI / dis);
				int vertixy = X.y + radius * sin(i * 2 * M_PI / dis);
				arrz[i] = vertixx;
				arrm[i] = vertixy;
			}
			color c1 = pControl->stringtocolor(color1);
			Info.DrawClr = c1;
			if (color2 != "NO_FILL") {
				color c2 = pControl->stringtocolor(color2);
				Info.FillClr = c2;
				Info.isFilled = true;
			}
			else {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
		}	pUI->DrawRPolygon(arrx, arrY, dis, Info);

	}
}