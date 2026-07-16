#include "Data.hpp"
#include "Colors.hpp"

Data::Data(std::string str)
	: _str(str)
{
	std::cout << PURPLE << "Data class initialized" << RESET << std::endl;
}

Data &Data::operator=(const Data &src)
{
	(void)src;
	return *this;
}

Data::~Data()
{
	std::cout << "Data destructor called" << std::endl;
}

std::string Data::getString() const
{
	return _str;
}