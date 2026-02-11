
#include "FragTrap.hpp"

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
		this->name = copy.name;
		this->hp = copy.hp;
		this->ep = copy.ep;
		this->dmg = copy.dmg;
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

void FragTrap::highFiveGuys(void)
{
	std::cout << name << " high fived the enemy... nice" << std::endl;
}
