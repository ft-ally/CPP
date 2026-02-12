
#ifndef WRONGAAnimal_HPP
#define WRONGAAnimal_HPP

#include <string>
#include <iostream>

class WrongAAnimal
{
	protected:
	std::string type;
	public:
	WrongAAnimal();
	virtual ~WrongAAnimal();
	WrongAAnimal(const WrongAAnimal &src);
	WrongAAnimal &operator=(const WrongAAnimal &src);
	std::string getType() const;
	void makeSound() const;
};


#endif