#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "Colors.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	AMateria	*learnedMateria[4];
	
	public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource& operator=(const MateriaSource &src);

	~MateriaSource();
	void learnMateria(AMateria *m) override;
	AMateria* createMateria(std::string const& type) override;

};

#endif