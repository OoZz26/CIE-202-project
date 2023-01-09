#include "Triangle.h"
Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Triangle::~Triangle()
{}

bool Triangle::IsINSHAPE(Point test) {

	float area_T, area1, area2, area3,sum_area;
	area_T = tri_area(Corner1, Corner2, Corner3);
	area1= tri_area(Corner1, Corner2, test);
	area2 = tri_area(Corner1, Corner3, test);
	area3 = tri_area(Corner3, Corner2, test);
	sum_area = area1 + area2 + area3;

	if ( area_T==sum_area ) {

		return true;
	}
	else
		return false;
}


void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawTri to draw a Triangle on the screen	
	pUI->DrawTri(Corner1, Corner2,Corner3, ShpGfxInfo,scrambled,duplicated);
}
void Triangle::Duplicate(GUI* pUI)
{
 
		Corner1.x = Corner1.x + 150;
		Corner2.x = Corner2.x + 150;
		Corner1.y = Corner1.y + 150;
		Corner2.y = Corner2.y + 150;
		Corner3.x = Corner3.x + 150;
		Corner3.y = Corner3.y + 150;
		//pUI->DuplicateRect(Corner1, Corner2, ShpGfxInfo);

}
void Triangle::Resize(double factor) {
	Point center;
	center.x = ((Corner1.x) + (Corner2.x) + (Corner3.x)) / 3;
	center.y = ((Corner1.y) + (Corner2.y) + (Corner3.y)) / 3;
	Corner1.x = factor * Corner1.x - factor * (center.x) + (center.x);
	Corner1.y = factor * Corner1.y- factor * (center.y) + (center.y);

	Corner2.x = factor * Corner2.x - factor * (center.x) + (center.x);
	Corner2.y = factor * Corner2.y - factor * (center.y) + (center.y);

	Corner3.x = factor * Corner3.x - factor * (center.x) + (center.x);
	Corner3.y = factor * Corner3.y - factor * (center.y) + (center.y);
}
void Triangle::Rotate() {
	Point center;
	center.x = ((Corner1.x) + (Corner2.x) + (Corner3.x)) / 3;
	center.y = ((Corner1.y) + (Corner2.y) + (Corner3.y)) / 3;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	int Temp3x = Corner3.x;
	int Temp3y = Corner3.y;
	Corner1.x = -Temp1y + center.x + center.y;
	Corner1.y = Temp1x - center.x + center.y;
	Corner2.x = -Temp2y + center.x + center.y;
	Corner2.y = Temp2x - center.x + center.y;
	Corner3.x = -Temp3y + center.x + center.y;
	Corner3.y = Temp3x - center.x + center.y;
	

}


string Triangle::save(ofstream& savefile, string filename, string fcl, string drc, string pnw) {
	if (ShpGfxInfo.isFilled = true) {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = colortostring(ShpGfxInfo.FillClr);
		string info = "Triangle " + to_string(Corner1.x) + " " + to_string(Corner1.y) + " " + to_string(Corner2.x) + " " + to_string(Corner2.y) + " " + to_string(Corner3.x) + " " + to_string(Corner3.y) + " " + x + " " + y;
		return info;
	}
	else

	{
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = "NO_FILL";
		string info = "Triangle " + to_string(Corner1.x) + " " + to_string(Corner1.y) + " " + to_string(Corner2.x) + " " + to_string(Corner2.y) + " " + to_string(Corner3.x) + " " + to_string(Corner3.y) + " " + x + " " + y;
		return info;
	}
}
int* Triangle::Getshapeparameters() {
	int listofparameters[4];
	int t=getsmallest(Corner1.x, Corner2.x, Corner3.x);
	int p = getsmallest(Corner1.y, Corner2.y, Corner3.y);
	int j = getbiggest(Corner1.x, Corner2.x, Corner3.x);
	int s = getbiggest(Corner1.y, Corner2.y, Corner3.y);
	listofparameters[0] = t - 10;
	listofparameters[1] = p - 10;
	listofparameters[2] = j - t + 15;
	listofparameters[3] = s - p + 15;
	return listofparameters;
}
int Triangle::getsmallest(int k, int n, int l) {
	if (k <= n && k <= l) {
		return k;
	}
	if (n <= k && n <= l) {
		return n;
	}
	if (l <= n && l <= k) {
		return l;
	}
}
int Triangle::getbiggest(int k, int n, int l) {
	if (k >= n && k >= l) {
		return k;
	}
	if (n >= k && n >= l) {
		return n;
	}
	if (l >= n && l >= k) {
		return l;
	}
}
void Triangle::Move(int& e, int& s)
{
	Point center;
	center.x = ((Corner1.x) + (Corner2.x) + (Corner3.x)) / 3;
	center.y = ((Corner1.y) + (Corner2.y) + (Corner3.y)) / 3;
	int dx, dy;
	dx = center.x - e;
	dy = center.y - s;
	Corner1.x = Corner1.x - dx;
	Corner2.x = Corner2.x - dx;
	Corner1.y = Corner1.y - dy;
	Corner2.y = Corner2.y - dy;
	Corner3.x = Corner3.x - dx;
	Corner3.y = Corner3.y - dy;

	/*srand(time(0));
	double dist1y = (Corner1.y - Corner2.y);
	double dist1x = (Corner1.x - Corner2.x);
	Corner1.x = (rand() % 1000);
	Corner1.y = (rand() % 500);
	Corner2.x = Corner1.x - dist1x;
	Corner2.y = Corner1.y - dist1y;*/


}

Point Triangle::GetCorner1()
{
	return Corner1;
}
Point Triangle::GetCorner2()
{
	return Corner2;
}

Point Triangle::GetCorner3()
{
	return Corner3;
}
void Triangle::zoom(double s) {
	Corner1.x = s * Corner1.x;
	Corner1.y = s * Corner1.y;
	s;
	Corner2.x = s * Corner2.x;
	Corner2.y = s * Corner2.y;
	s;
	Corner3.x = s * Corner3.x;
	Corner3.y = s * Corner3.y;

}

