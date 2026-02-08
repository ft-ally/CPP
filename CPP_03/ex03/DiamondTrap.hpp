
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, ScavTrap
{
	std::string name;
	
	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &newDiamond);
	DiamondTrap &operator=(const DiamondTrap copy);
	
	void whoAmI();
};

DiamondTrap::DiamondTrap()
	: FragTrap(), ScavTrap()
{

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	:name(name), ScavTrap(name), FragTrap(name) 
{
	ClapTrap:: name
	hp = FragTrap::FRAG_HP;
	ep = ScavTrap::SCAV_EP;
	dmg = FragTrap::FRAG_DMG;
	
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap deconstructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &newDiamond)
	:ScavTrap(newDiamond), FragTrap(newDiamond)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = newDiamond;
}


#endif