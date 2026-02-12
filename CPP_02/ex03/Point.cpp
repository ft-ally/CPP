
#include "Point.hpp"

Point::Point()
	:x (0), y(0)
{}
Point::Point(const float i, const float j)
	:x(i), y(j)
{}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}
Point::Point(const Point &src) //copy constructor
	: x(src.x), y(src.y)
{
}

Point& Point::operator=(const Point &src) //copy assignment operator
{
	(void)src;
	return *this;
}

int Point::x_val() const
{
	return(this->x.getRawBits());
}
int Point::y_val() const
{
	return (this->y.getRawBits());
}


