#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
	Brain	*catBrain;
	
	public:
	Cat();
	Cat(std::string thought);
	~Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	
	std::string getType() const override;
	void makeSound() const override;
	void sayIdeas() const override;


};

#endif