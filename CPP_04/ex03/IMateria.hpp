#ifndef IMATERIA_HPP
#define IMATERIA_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria* createMateria(std::string const& type) = 0;
};

class MateriaSource : public IMateriaSource
{
	AMateria	*learnedMateria[4];
	
	public:
	~MateriaSource();
	void learnMateria(AMateria *) = 0;
	AMateria* createMateria(std::string const& type) = 0;

};

#endif