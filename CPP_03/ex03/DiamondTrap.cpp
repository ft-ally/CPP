
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	:FragTrap(name), ScavTrap(name), name(name) 
{
	ClapTrap::name = name + "_clap_name";
	hp = FragTrap::FRAG_HP;
	ep = ScavTrap::SCAV_EP;
	dmg = FragTrap::FRAG_DMG;
	std::cout << "DiamondTrap constructor called" << std::endl;
	
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap deconstructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &newDiamond)
	:FragTrap(newDiamond), ScavTrap(newDiamond)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = newDiamond;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->hp = copy.hp;
		this->ep = copy.ep;
		this->dmg = copy.dmg;
	}
	std::cout << "Diamond trap copy assignment operator called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::string clap_name = this->ClapTrap::getName();
	std::cout << "I am Diamond Trap " << name << " also known as " << clap_name << std::endl;
}