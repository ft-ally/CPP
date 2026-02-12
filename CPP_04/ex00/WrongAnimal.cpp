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

WrongAnimal::WrongAnimal(const WrongAnimal &newWrongAnimal)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = newWrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
		this->type = copy.type;
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
