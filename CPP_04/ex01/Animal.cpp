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

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = src.type;
}

Animal& Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
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