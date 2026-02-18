#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
	const Fixed x;
	const Fixed y;

	public:
	Point();
	Point(const float i, const float j);
	~Point();
	Point(const Point &src); //copy constructor
	Point &operator=(const Point &src); //copy assignment operator
	int x_val() const;
	int y_val() const;


};

float calculate_area(int x1, int y1, int x2, int y2, int x3, int y3);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif