#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog::Dog(const Dog &newDog) : Animal(newDog)
{
	std::cout << "Dog default copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof!!" << std::endl;
}
