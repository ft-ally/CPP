#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Colors.hpp"


class Character : public ICharacter
{
	private:
	std::string name;
	AMateria 	*inventory[4];
	AMateria	*floor[10];
	
	public:
	Character();
	~Character();
	Character(std::string name);
	Character(const Character &src);
	Character& operator=(const Character &src);
	
	void putOnFloor(AMateria *m);
	std::string const &getName() const override;
	void equip(AMateria *m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;
};

Character::Character()
	:name("default") 
{
	std::cout << YELLOW << "Character default constructor called\n" << RESET;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 10; i++)
		floor[i] = NULL;
}

Character::~Character()
{
	std::cout << YELLOW << "Character deconstructor called\n" << RESET;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete (inventory[i]);
			inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (floor[i])
		{
			delete (floor[i]);
			floor[i] = NULL;
		}
	}
}

Character::Character(std::string name)
	: name(name)
{
	std::cout << YELLOW << "Character " << name << " created!\n" << RESET;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 10; i++)
		floor[i] = NULL;
}

Character::Character(const Character &src)
{
	std::cout << YELLOW << "Character copy constructor called\n" << RESET;
	for (int i = 0; i < 4; i++)
	{
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	for (int i = 0; i < 10; i++)
		floor[i] = NULL;
}

Character& Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->name = src.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete (this->inventory[i]);
		}
		for (int i = 0; i < 4; i++)
		{
			if (src.inventory[i])
				this->inventory[i] = src.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
		for (int i = 0; i < 10; i++)
		{
			if (this->floor[i])
				delete (this->floor[i]);
		}
		for (int i = 0; i < 10; i++)
			floor[i] = NULL;
	}
	return (*this);
}


std::string const& Character::getName() const
{
	return (name);
}

void Character::putOnFloor(AMateria *m)
{
	for (int i = 0; i < 10; i++)
	{
		if (floor[i] == NULL)
		{
			floor[i] = m;
			return ;
		}
	}
}

void Character::equip(AMateria *m)
{
	if (!m)
		std::cout << YELLOW << "Cannot equip empty materia\n" << RESET;
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] == NULL)
			{
				this->inventory[i] = m;
				return ;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return ;
	else
	{
		if (this->inventory[idx])
		{
			putOnFloor(this->inventory[idx]);
			this->inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		return ;
	else
	{
		if (this->inventory[idx])
			this->inventory[idx]->use(target);
		else
			return ;
	}
}
#endif