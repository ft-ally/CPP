#ifndef AMATERIA_HPP
#define AMAETERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
	std::string type;

	public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &src);
	AMateria &operator=(const AMateria &src);
	virtual ~AMateria();
	std::string const& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif