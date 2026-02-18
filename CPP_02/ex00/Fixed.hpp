
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	int					fx;
	static const int	fr = 8;

	public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &src); //copy constructor
	Fixed &operator=(const Fixed &src); //copy assignment overload
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif

