
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	protected:
	std::string ideas[100];
	
	public:
	Brain();
	Brain(std::string thought);
	~Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	void sayThreeIdeas() const;
	void plantIdeas(std::string newIdea);
};

#endif