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
	
	float toFloat(void) const ; //convert fixed to float
	int	getRawBits(void) const;

	bool operator>(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator<(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;
	
	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj);
	Fixed operator/(const Fixed &obj);

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min (const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max (const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& str, const Fixed& obj);

#endif

