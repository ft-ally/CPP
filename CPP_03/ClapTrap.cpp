
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
{
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &newPlayer)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = newPlayer;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hp = copy.hp;
		this->ep = copy.ep;
		this->dmg = copy.dmg;
	}
	return (*this);
}

std::string ClapTrap::getName() const
{
	return this->name;
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
			<< "HP remaining:" << hp << std::endl
			<< "EP remaining:" << ep << std::endl;
			
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
		std::cout << "The robot is dead.. RIP" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "HP remaining:" << hp << std::endl
			<< "EP remaining:" << ep << std::endl;
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
		std::cout << "Healsies! Claptrap " << name 
			<< " heals itself for " << amount 
			<< " hp!" << std::endl
			<< "HP remaining:" << hp << std::endl
			<< "EP remaining:" << ep << std::endl;
	}
}

std::string ClapTrap::initiateStart()
{
	std::string name;
	std::cout << "________________________________" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "| Welcome to ClapTrap Battle!!|" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "|_____________________________|" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter ClapTrap Name: ";
	if (!std::getline(std::cin, name))
		exit(0) ;
	usleep(1000000);
	std::cout << "ClapTrap " << name << " is ready for battle!" << std::endl;
	usleep(1000000);
	std::cout << "ClapTrap Boss is ready for battle!" << std::endl;
	return (name);
}

int ClapTrap::startGame()
{
	this->name = initiateStart();
	std::string enemy= "ClapTrap Boss";
	int enemy_hp = 100;
	int amount = 1;

	while (1)
	{
		std::random_device rnd;
		std::uniform_int_distribution<int> gen{1, 10};
		std::cout << std::endl;
		int roll = gen(rnd);
		std::cout << "ClapTrap Boss rolls " << roll << "!"
		<< std::endl;
		usleep(1000000);
		if (roll % 2 == 0)
		{
			if (!takeDamage(roll))
				break ;
		}
		else
		{
			std::cout << "ClapTrap Boss hurts itself in confusion for " << roll << " damage!" << std::endl;
			enemy_hp = enemy_hp-roll;
			if (enemy_hp < 1)
			{
				std::cout << "Ya killed him!! Yay!!" << std::endl << std::endl;
					return (0);
			}
			else
				std::cout << "Claptrap Boss HP: " << enemy_hp << std::endl;
		}
		std::string input;
		usleep(1000000);
		std::cout << std::endl << "Your move, cowboy!" << std::endl;
		std::cout << "ATTACK | HEAL | EXIT" << std::endl;
		if (!std::getline(std::cin, input))
			exit(0) ;
		if (input == "ATTACK" || input == "attack")
		{
			attack(enemy);
			if (enemy_hp < 1)
			{
				std::cout << "Ya killed him!! Yay!!" << std::endl;
					return (0);
			}
			else
				std::cout << "Claptrap Boss HP: " << enemy_hp << std::endl;
		}
		if (input == "HEAL" || input == "heal")
		{
			beRepaired(amount);
			this->hp +=1;
		}
		if (input == "EXIT" || input == "exit")
			break ;
	
	}
	return (0);
}
