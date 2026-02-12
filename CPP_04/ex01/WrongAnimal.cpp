#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "Wrong animal :(";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "Default copy constructor operator called" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "*random WrongAnimal noises*" << std::endl;
}
