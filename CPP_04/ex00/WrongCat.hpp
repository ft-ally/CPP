
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &newWrongCat);
	WrongCat &operator=(const WrongCat &copy);
	void makeSound() const;
};

