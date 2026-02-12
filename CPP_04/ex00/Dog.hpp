#include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog();
	~Dog();
	Dog(const Dog &newDog);
	Dog &operator=(const Dog &copy);
	void makeSound() const override;
};
