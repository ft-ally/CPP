
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(""), FragTrap(), ScavTrap(), name("")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) 
{
	hp = FragTrap::FRAG_HP;
	ep = ScavTrap::SCAV_EP;
	dmg = FragTrap::FRAG_DMG;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap deconstructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
	:ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	this->name = src.name;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->dmg = src.dmg;
	}
	std::cout << "Diamond trap copy assignment operator called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::string clap_name = this->ClapTrap::getName();
	std::cout << "I am Diamond Trap " << name << " also known as " << clap_name << std::endl;
}