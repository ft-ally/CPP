
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "no thoughts here...";
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain::Brain(std::string thought)
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = thought;
}
Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" <<std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain& Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

void Brain::sayThreeIdeas() const
{
	for (int i = 0; i < 3; i++)
		std::cout << "Idea #" << i + 1 << ": " << ideas[i] << std::endl;
}

void Brain::plantIdeas(std::string newIdea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = newIdea;
	
}
