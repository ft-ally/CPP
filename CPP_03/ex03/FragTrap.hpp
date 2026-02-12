#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &src);
	
	void highFiveGuys(void);
	const static int FRAG_HP = 100;
	const static int FRAG_EP = 100;
	const static int FRAG_DMG = 30;
};

#endif