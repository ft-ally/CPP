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
	void equip(AMateria *m) override;
	std::string const &getName() const override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;
};


#endif