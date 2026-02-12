
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
	std::string type;
	public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &src);
	std::string getType() const;
	void makeSound() const;
};


#endif