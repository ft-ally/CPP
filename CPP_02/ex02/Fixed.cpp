#include "Fixed.hpp"


Fixed::Fixed()
{
	fx = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fx = num << fr;
}
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called"  << std::endl;
	this->fx = roundf(num * (1 << fr));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called"  << std::endl;
	this->fx = src.fx; 
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called"  << std::endl;	
	if (this != &src)
		fx = src.fx; //CHECK
	return (*this);
}

float Fixed::toFloat(void) const
{
	return ((float)fx / (1 << fr));
}

/// Comparison operator overloads ///

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->fx > obj.fx);
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->fx >= obj.fx);
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->fx < obj.fx);
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->fx <= obj.fx);
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->fx == obj.fx);
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->fx != obj.fx);
}

/// Arithmetic operator overload//

Fixed Fixed::operator+(const Fixed &obj)
{
	Fixed res;
	res.fx = this->fx + obj.fx;
	return (res);
}

Fixed Fixed::operator-(const Fixed &obj)
{
	Fixed res;
	res.fx = this->fx - obj.fx;
	return (res);
}

Fixed Fixed::operator*(const Fixed &obj)
{
	Fixed res;
	res.fx = (this->fx * obj.fx) >> fr;
	return (res);
}
//* and / operators bit shift bc of scale
//res.fx = this.fx * 2^8 * obj.fx * 2^8 << shift to cancel 1 2^8

Fixed Fixed::operator/(const Fixed &obj)
{
	Fixed res;
	res.fx = (this->fx / obj.fx) << fr;
	return (res);
}

/// Increment / Decrement overloads ///

//preincrement (++a), returns modified ref
Fixed& Fixed::operator++()
{
	++this->fx;
	return (*this);
}
//postincrement(a++), passes 0, returns copy
//so it returns old object before it increments
Fixed Fixed::operator++(int)
{
	Fixed res = *this;
	++this->fx;
	return (res);
}

Fixed &Fixed::operator--()
{
	--this->fx;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed res = *this;
	--this->fx;
	return(res);
}

//Min max
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.fx < b.fx)
		return (a);
	return (b);
}

const Fixed& Fixed::min (const Fixed &a, const Fixed &b)
{
	if (a.fx < b.fx)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.fx > b.fx)
		return (a);
	return (b);
}

const Fixed& Fixed::max (const Fixed &a, const Fixed &b)
{
	if (a.fx > b.fx)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream& str, const Fixed& obj)
{
	str << obj.toFloat();
	return (str);
}