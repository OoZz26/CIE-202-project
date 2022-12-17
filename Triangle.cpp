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
	pUI->DrawTri(Corner1, Corner2,Corner3, ShpGfxInfo);
}
