#include "Cat.hpp"

Cat::Cat() : Animal()
{
	catBrain = new Brain();
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string thought) : Animal()
{
	catBrain = new Brain(thought);
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete (catBrain);
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	catBrain = new Brain(*src.catBrain);

}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "Cat copy operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
		delete (catBrain);
		catBrain = new Brain(*src.catBrain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::sayIdeas() const
{
	catBrain->sayThreeIdeas();
}