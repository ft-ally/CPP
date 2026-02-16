
#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << BLUE << "Icharacter default constructor called\n" << RESET;
}

ICharacter::ICharacter(const ICharacter &src)
{
	std::cout << BLUE << "ICharacter copy constructor called\n" << RESET;
	*this = src;
}

ICharacter& ICharacter::operator=(const ICharacter &src)
{
	(void)src;
	std::cout << BLUE << "ICharacter copy assignment operator called\n" << RESET;
	return (*this);
}

ICharacter::~ICharacter()
{
	std::cout << BLUE << "ICharacter destructor called\n" << RESET;
}

