
#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>
#include <random>
#include <unistd.h>

ClapTrap::ClapTrap()
	:name(""),hp(10), ep(10), dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:name(name), hp(10), ep(10), dmg(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->dmg = src.dmg;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::string ClapTrap::getName() const
{
	return this->name;
}

int ClapTrap::getDamage() const
{
	return (this->dmg);
}

void ClapTrap::attack(const std::string &target)
{

	if (this->hp < 1)
		std::cout << "The robot known as ClapTrap " << name << " is dead.. RIP" << std::endl;
	else
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
				<< "HP remaining:" << hp << std::endl
				<< "EP remaining:" << ep << std::endl;
		}	
	}
}

int ClapTrap::takeDamage(unsigned int amount)
{
	hp -=amount;
	
	std::cout << "Youch! Claptrap " << name 
			<< " takes " << amount 
			<< " damage!" << std::endl;
	if (this->hp < 1)
	{ 
		std::cout << "The robot known as ClapTrap " << name << " is dead.. RIP" << std::endl;
		return(0);
	}
	else
	{
		std::cout << "HP remaining: " << hp << std::endl
			<< "EP remaining: " << ep << std::endl;
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
	if (hp >= 10)
	{
		std::cout << "HP is full!"
			<<std::endl;
	}
	else
	{
		ep -= 1;
		hp += amount;
		std::cout << "Healsies! Claptrap " << name 
			<< " heals itself for " << amount 
			<< " hp!" << std::endl
			<< "HP remaining: " << hp << std::endl
			<< "EP remaining: " << ep << std::endl;
	}
}
