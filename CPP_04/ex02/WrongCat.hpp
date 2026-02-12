#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAAnimal.hpp"

class WrongCat : public WrongAAnimal
{
	public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &src);
	void makeSound() const;
};

#endif