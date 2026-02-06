
#include "Point.hpp"
#include "Fixed.hpp"

float calculateArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float area;
	area = (((x1*(y2 - y3)) + (x2*(y3 - y1)) + (x3* (y1 - y2))) / 2);
	
	if (area > 0)
		area *= -1;
	return (area);
}

bool edgeCheck(int a, int b, int c, int p)
{

}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Fixed high;
	// Fixed low;
	//need to check for vertices and edges 
	int x1 = a.x_val();
	int y1 = a.y_val();
	int x2 = b.x_val();
	int y2 = b.y_val();
	float x3 = c.x_val();
	float y3 = c.y_val();
	float p1 = point.x_val();
	float p2 = point.y_val();
	
	float areaABC = calculateArea(x1, y1, x2, y2, x3, y3);
	float areaPBC = calculateArea(p1, p2, y1, y2, x3, y3);
	float areaAPC = calculateArea(x1, y1, p1, p2, x3, y3);
	float areaABP = calculateArea(x1, y1, x2, y2, p1, p2);
	float pointTotalArea = areaPBC + areaAPC + areaABP;
	if (pointTotalArea != areaABC)
		return (false);
	else
		return (true);
	
}

