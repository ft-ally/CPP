#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap ()
{
	hp = SCAV_HP;
	ep = SCAV_EP;
	dmg = SCAV_DMG;
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
	:ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->dmg = src.dmg;
	}
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
		std::cout << name 
			<< " throws a bomb at " << target 
			<< " for " << dmg 
			<< " damage!!!" << std::endl
			<< "****HP remaining:" << hp << std::endl
			<< "****EP remaining:" << ep << std::endl;
			
	}
}
void ScavTrap::guardGate()
{
	std::cout << name << " is now in GATEKEEPER mode"
		<< std::endl
		<< "It doesn't do anything..." 
		<< std::endl;
}


