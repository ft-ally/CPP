
#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	~Cat();
	Cat(const Cat &newCat);
	Cat &operator=(const Cat &copy);
	void makeSound();
};

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat::Cat(const Cat &newCat) : Animal(newCat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = "Cat";
}

Cat& Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void Cat::makeSound()
{
	std::cout << "Meow" << std::endl;
}