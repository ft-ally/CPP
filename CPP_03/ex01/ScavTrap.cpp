#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap ("")
{
	hp = 100;
	ep = 50;
	dmg = 20;
	std::cout << "ScavTrap default constructor called"
		<< std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap (name)
{
	hp = 100;
	ep = 50;
	dmg = 20;
	std::cout << "ScavTrap constructor called"
		<< std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called"
		<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
	: ClapTrap (src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}
//no need to call this = src, because srcclaptrap's values are already set to scav
//plus there are no other vars

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->dmg = src.dmg;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (ep < 1)
	{
		std::cout << "Out of energy!"
			<< std::endl;
	}
	else
	{
		ep -= 1;
		std::cout << "ScavTrap " << name 
			<< " throws a bomb at " << target 
			<< " for " << dmg 
			<< " damage!!!" << std::endl
			<< "****HP remaining:" << hp << std::endl
			<< "****EP remaining:" << ep << std::endl;
			
	}
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in GATEKEEPER mode"
		<< std::endl
		<< "It doesn't do anything..." 
		<< std::endl;
}


