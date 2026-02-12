
#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	~Cat();
	Cat(const Cat &newCat);
	Cat &operator=(const Cat &copy);
	void makeSound() const override;
};

