
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>


class ScavTrap : virtual public ClapTrap
{

	public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &src); //copy constructor
	ScavTrap &operator=(const ScavTrap &src); //copy assignment overload

	void attack(const std::string &target);
	void guardGate();
	static const int SCAV_HP = 100;
	static const int SCAV_EP = 50;
	static const int SCAV_DMG = 20;
};


#endif