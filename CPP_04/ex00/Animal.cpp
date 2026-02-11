#include "Animal.hpp"

Animal::Animal()
{
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

void Animal::makeSound()
{
	std::cout << "*random animal noises*" << std::endl;
}

void Animal::setType(std::string newType)
{
	this->type = newType;
}

void Animal::getType()
{
	std::cout << type;
}