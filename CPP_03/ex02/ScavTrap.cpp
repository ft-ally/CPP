#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap ()
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

ScavTrap::ScavTrap(const ScavTrap &newScav)
	:ClapTrap(newScav)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = newScav;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->hp = copy.hp;
		this->ep = copy.ep;
		this->dmg = copy.dmg;
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


