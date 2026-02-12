#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain	*dogBrain;
	
	public:
	Dog();
	Dog(std::string thought);
	~Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);

	void makeSound() const override;
	void sayIdeas() const override;
	void plantIdeas(std::string thought);
};

#endif