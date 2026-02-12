#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	type = "AAnimal";
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal deconstructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = src.type;
}

AAnimal& AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	return (*this);
}
