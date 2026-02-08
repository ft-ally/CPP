
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>


class ScavTrap : public ClapTrap
{

	public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &newScav); //copy constructor
	ScavTrap &operator=(const ScavTrap &copy); //copy assignment overload

	void attack(const std::string &target);
	void guardGate();
	
	static const int fragHp = 100;
	static const int fragEp = 50;
	static const int fragDmg = 20;
};


#endif