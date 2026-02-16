#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "Colors.hpp"
#include "AMateria.hpp"

class IMateriaSource
{
	public:

	IMateriaSource();
	IMateriaSource(const IMateriaSource &src);
	IMateriaSource& operator=(const IMateriaSource &src);

	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif