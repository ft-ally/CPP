#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal::Animal(const Animal &newAnimal)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = newAnimal;
}

Animal& Animal::operator=(const Animal &copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "Default copy constructor operator called" << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "*random animal noises*" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}