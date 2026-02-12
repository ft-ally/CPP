
#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <string>
#include <iostream>

class AAnimal
{
	protected:
	std::string type;

	public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &src);
	virtual ~AAnimal();
	
	virtual void makeSound() const = 0;
	virtual void sayIdeas() const = 0;
	virtual std::string getType() const = 0;
};


#endif