
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
	hp = 100;
	ep = 100;
	dmg = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}	
FragTrap::~FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
	: ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->dmg = src.dmg;
	}
	std::cout << "FragTrap copy assignment constructor called" << std::endl;
	return (*this);
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->name << " high fived the enemy... nice"
		<< std::endl;
}