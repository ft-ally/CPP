#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
	private:
	std::string name;
	int hp;
	int ep;
	int dmg;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &src);

	std::string getName() const;
	int getDamage() const;
	void attack(const std::string &target);
	int takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif