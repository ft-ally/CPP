#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	int					fx;
	static const int	fr = 8;

	public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(const Fixed &src); //copy constructor
	Fixed &operator=(const Fixed &src); //copy assignment operator
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const ; //convert fixed to float
	int toInt(void) const; //convert float to int
};

std::ostream& operator<<(std::ostream& str, const Fixed& obj);

#endif

