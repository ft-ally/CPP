#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
	protected:
	std::string name;
	int hp;
	int ep;
	int dmg;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &src); //copy constructor
	ClapTrap &operator=(const ClapTrap &src); //copy assignment overload

	std::string getName() const;
	int getDamage() const;

	void attack(const std::string &target);
	int takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif