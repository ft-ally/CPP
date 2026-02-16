
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	: IMateriaSource()
{
	// std::cout << MAGENTA << "MateriaSource default constructor called\n" << RESET;
	for (int i = 0; i < 4; i++)
		learnedMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if (src.learnedMateria[i])
			this->learnedMateria[i] = src.learnedMateria[i]->clone();
		else
			this->learnedMateria[i] = NULL;
	}
		
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	// std::cout << MAGENTA << "MateriaSource copy assignment operator called\n" << RESET;
	for (int i = 0; i < 4; i++)
	{
		if (this->learnedMateria[i])
			delete (this->learnedMateria[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		if (src.learnedMateria[i])
			this->learnedMateria[i] = src.learnedMateria[i];
		else
			this->learnedMateria[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	// std::cout << MAGENTA << "MateriaSource deconstructor called\n" << RESET;
	for (int i = 0; i < 4; i++)
	{
		if (this->learnedMateria[i])
			delete (this->learnedMateria[i]);
	}
}


void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!m)
		{
			std::cout << "Cannot learn empty materia\n";
			return ;
		}
		if (!this->learnedMateria[i])
		{
			this->learnedMateria[i] = m;
			std::cout << MAGENTA << m->getType() << " was added to learned materia\n" << RESET;
			return ;
		}
	}
	std::cout << RED << "Slots too full to learn new materia!\n" << RESET;
	delete m;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->learnedMateria[i] && this->learnedMateria[i]->getType() == type)
			return (this->learnedMateria[i]->clone());
	}
	return (NULL);
}
