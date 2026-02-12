
#ifndef ICE_HPP
#define ICE_HPP

#include "Colors.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
	
	public:
	Ice();
	Ice(const Ice &src);
	Ice &operator=(const Ice &src);
	~Ice();
	
	AMateria* clone() const;
	void use(ICharacter& target);
};

Ice::Ice()
: AMateria("ice")
{
	std::cout << BLUE << "Ice default constructor called\n" << RESET;
}

Ice::~Ice()
{
	std::cout << BLUE << "Ice deconstructor called\n" << RESET;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << BLUE << "Ice copy constructor called\n" << RESET;
}

Ice& Ice::operator=(const Ice &src)
{
	if (this != &src)
		this->type = src.type;
	return (*this);
	std::cout << BLUE << "Ice copy assignment operator called\n" << RESET;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}

#endif