#include "Dog.hpp"

Dog::Dog() : Animal()
{
	dogBrain = new Brain();
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(std::string thought) : Animal()
{
	dogBrain = new Brain(thought);
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete (dogBrain);
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog::Dog(const Dog &newDog) : Animal(newDog)
{
	dogBrain = new Brain(*newDog.dogBrain);
	std::cout << "Dog default copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		this->type = src.type;
		delete (dogBrain);
		dogBrain = new Brain(*src.dogBrain);
	}
	std::cout << "Dog default copy assignment operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof!!" << std::endl;
}

void Dog::sayIdeas() const
{
	dogBrain->sayThreeIdeas();
}

void Dog::plantIdeas(std::string thought)
{
	dogBrain->plantIdeas(thought);
}