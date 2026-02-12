#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal()
{
	type = "Wrong AAnimal :(";
	std::cout << "WrongAAnimal constructor called" << std::endl;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "WrongAAnimal deconstructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

WrongAAnimal& WrongAAnimal::operator=(const WrongAAnimal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "Default copy constructor operator called" << std::endl;
	return (*this);
}

std::string WrongAAnimal::getType() const
{
	return (type);
}

void WrongAAnimal::makeSound() const
{
	std::cout << "*random WrongAAnimal noises*" << std::endl;
}
