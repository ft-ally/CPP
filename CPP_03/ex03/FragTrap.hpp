#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &newFrag);
	FragTrap &operator=(const FragTrap &copy);
	
	void highFiveGuys(void);
	const static int FRAG_HP = 100;
	const static int FRAG_EP = 100;
	const static int FRAG_DMG = 30;
};

FragTrap::FragTrap()
	: ClapTrap()
{
	hp = 100;
	ep = 100;
	dmg = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	hp = FRAG_HP;
	ep = FRAG_EP;
	dmg = FRAG_DMG;
	std::cout << "FragTrap constructor called" << std::endl;
}	
FragTrap::~FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &newFrag)
	: ClapTrap(newFrag)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = newFrag;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
	}
	std::cout << "FragTrap copy constructor called" << std::endl;
	return (*this);
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap high fived the enemy... nice"
		<< std::endl;
}
#endif