#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
	Brain	*catBrain;
	
	public:
	Cat();
	Cat(std::string thought);
	~Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	
	void makeSound() const override;
	void sayIdeas() const override;

};

#endif