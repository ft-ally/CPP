#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include "AMateria.hpp"

class ICharacter
{
	public:
		ICharacter();
		ICharacter(const ICharacter &src);
		ICharacter& operator=(const ICharacter &src);
		virtual ~ICharacter();
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

ICharacter::ICharacter()
{
	std::cout << "Icharacter default constructor called\n";
}

ICharacter::ICharacter(const ICharacter &src)
{
	std::cout << "ICharacter copy constructor called\n";
	*this = src;
}

ICharacter& ICharacter::operator=(const ICharacter &src)
{
	(void)src;
	std::cout << "ICharacter copy assignment operator called\n";
	return (*this);
}

ICharacter::~ICharacter()
{
	std::cout << "ICharacter destructor called\n";
}

#endif