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
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called"  << std::endl;
	if (this != &src)
		fx = src.fx;
	return (*this);
}

float Fixed::toFloat(void) const
{
	return ((float)fx / (1 << fr));
}

int Fixed::toInt(void) const
{
	return ((int)fx >> fr);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	std::cout << fx << std::endl;
	return (fx);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	fx = raw;
}

//Overloads << str is left of << in the stream, obj is right
std::ostream &operator<<(std::ostream& str, const Fixed& obj)
{
	str << obj.toFloat();
	return (str);
}
