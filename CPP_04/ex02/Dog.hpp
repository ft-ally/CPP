#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
	std::string getType() const override;
	void plantIdeas(std::string thought);
};

#endif