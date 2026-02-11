
#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>


ClapTrap::ClapTrap()
	:name(""),hp(10), ep(10), dmg(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:name(name), hp(10), ep(10), dmg(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &newPlayer)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = newPlayer;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->hp = copy.hp;
		this->ep = copy.ep;
		this->dmg = copy.dmg;
	}
	std::cout << "CT copy assignment operator called" << std::endl;
	return (*this);
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

int ClapTrap::getDamage() const
{
	return (this->dmg);
}

void ClapTrap::attack(const std::string &target)
{
	if (ep < 1)
	{
		std::cout << "Out of energy!"
			<< std::endl;
	}
	else
	{
		ep -= 1;
		std::cout << "Hyah! ClapTrap " << name 
			<< " attacks " << target 
			<< " for " << dmg 
			<< " damage!!!" << std::endl
			<< "****HP remaining:" << hp << std::endl
			<< "****EP remaining:" << ep << std::endl;
			
	}
}

int ClapTrap::takeDamage(unsigned int amount)
{
	hp -=amount;
	
	std::cout << "Youch! " << name 
			<< " takes " << amount 
			<< " damage!" << std::endl;
	if (this->hp < 1)
	{ 
		std::cout << "The robot known as " << name << " is dead.. RIP" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "****HP remaining: " << hp << std::endl
			<< "****EP remaining: " << ep << std::endl;
	}
	return (1);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (ep < 1)
	{
		std::cout << "Out of energy!"
			<< std::endl;
	}
	else
	{
		ep -= 1;
		hp += amount;
		std::cout << "Healsies! " << name 
			<< " heals itself for " << amount 
			<< " hp!" << std::endl
			<< "****HP remaining: " << hp << std::endl
			<< "****EP remaining: " << ep << std::endl;
	}
}
