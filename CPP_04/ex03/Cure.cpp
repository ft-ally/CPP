
#include "Cure.hpp"


Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Cure default constructor called\n" << RESET;
}

Cure::~Cure()
{
	std::cout << GREEN << "Cure deconstructor called\n" << RESET;
}

Cure::Cure(const Cure &src)
	: AMateria(src)
{
	std::cout << GREEN << "Cure copy constructor called\n" << RESET;
}

Cure& Cure::operator=(const Cure &src)
{
	this->type = src.type;
	std::cout << GREEN << "Cure copy assignmment operator called\n" << RESET;
	return (*this);
}

AMateria* Cure::clone() const
{
	return(new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}

