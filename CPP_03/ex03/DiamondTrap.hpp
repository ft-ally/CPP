
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	std::string name;
	
	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &newDiamond);
	DiamondTrap &operator=(const DiamondTrap &copy);
	
	using ScavTrap::attack;
	void whoAmI();
};

#endif