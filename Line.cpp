#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	start = P1;
	end = P2;
}

Line::~Line()
{}
bool Line::IsINSHAPE(Point test) {
	double slope;
	int diff;
	
	slope = (((start.y) - (end.y))*1.0) / ((start.x) - (end.x));
	diff = abs(slope * ((test.x) - (start.x)) - ((test.y) - (start.y)));
	if (diff<=1 && test.x <= max((end.x), (start.x))
		&& test.x >= min((end.x), (start.x))) {
		return true;
	}
	else
		return false;



}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawL to draw a line on the screen	
	pUI->DrawL(start, end, ShpGfxInfo);
}
string Line::save(ofstream& savefile, string filename, string fcl, string drc, string pnw) {
	if (ShpGfxInfo.isFilled = true) {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = colortostring(ShpGfxInfo.FillClr);
		string info = "Line " + to_string(start.x) + " " + to_string(start.y) + " " + to_string(end.x) + " " + to_string(end.y) + " " + x + " " + y;
		return info;
	}
	else {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = "NO_FILL";
		string info = "Line " + to_string(start.x) + " " + to_string(start.y) + " " + to_string(end.x) + " " + to_string(end.y) + " " + x + " " + y;
		return info;

	}
}
void Line::Resize(double factor) {
	Point Center;

	Center.x = (start.x + end.x) / 2;
	Center.y = (start.y + end.y) / 2;

	start.x = factor * start.x - factor * (Center.x) + (Center.x);
	start.y = factor * start.y - factor * (Center.y) + (Center.y);

	end.x = factor * end.x - factor * (Center.x) + (Center.x);
	end.y = factor * end.y - factor * (Center.y) + (Center.y);
	

}
void Line:: Rotate(){
	Point center;
	center.x = ((start.x) + (end.x)) / 2;
	center.y = ((start.y) + (end.y)) / 2;

	int Temp1x = start.x;
	int Temp1y = start.y;
	int Temp2x = end.x;
	int Temp2y = end.y;

	start.x = -Temp1y + center.x + center.y;
	start.y = Temp1x - center.x + center.y;
	end.x = -Temp2y + center.x + center.y;
	end.y = Temp2x - center.x + center.y;

}

Point Line::GetStart()
{
	return start;
}
Point Line :: GetEnd()
{
	return end;
}