#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &newWrongCat) : WrongAnimal(newWrongCat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat copy operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat meows" << std::endl;
}
