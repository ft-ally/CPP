
#include "AMateria.hpp"


AMateria::AMateria()
{
	// std::cout << ORANGE << "AMat default constructor called\n" << RESET;
}

AMateria::AMateria(std::string const &type)
	:type(type)
{
	// std::cout << ORANGE << "AMat param constructor called\n" << RESET;
}

AMateria::AMateria(const AMateria &src)
{
	if (this!= &src)
		this->type = src.type;
	// std::cout << ORANGE << "AMat copy constructor called\n" << RESET;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	this->type = src.type;
	// std::cout << ORANGE << "AMat copy assignment operator called\n" << RESET;
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << ORANGE << "AMat deconstructor called\n" << RESET;
}

std::string const& AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "I am overloaded and will never be called, ya welcome " << target.getName() << std::endl;
}
