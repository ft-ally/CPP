
#include "IMateriaSource.hpp"


IMateriaSource::IMateriaSource()
{
	std::cout << MAGENTA << "IMateriaSource default constructor called\n" << RESET;
}

IMateriaSource::IMateriaSource(const IMateriaSource &src)
{
	std::cout << MAGENTA << "IMateriaSource copy constructor called\n" << RESET;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource &src)
{
	std::cout << MAGENTA << "IMateriaSource copy assignment operator called\n" << RESET;
}

IMateriaSource::~IMateriaSource()
{
	std::cout << MAGENTA << "IMateriaSource deconstructor called\n" << RESET;
}
