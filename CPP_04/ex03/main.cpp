#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }


int main()
{
    std::cout << "=== Test 1: Basic functionality ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    std::cout << "\n=== Test 2: Full inventory ===" << std::endl;
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());
    
    ICharacter* hero = new Character("hero");
    hero->equip(src2->createMateria("ice"));
    hero->equip(src2->createMateria("cure"));
    hero->equip(src2->createMateria("ice"));
    hero->equip(src2->createMateria("cure"));
    hero->equip(src2->createMateria("ice")); // Should fail (inventory full)
	std::cout << std::endl;
    
    ICharacter* enemy = new Character("enemy");
    hero->use(0, *enemy);
    hero->use(1, *enemy);
    hero->use(2, *enemy);
    hero->use(3, *enemy);
    hero->use(4, *enemy); // (out of bounds)
    
    std::cout << "\n=== Test 3: Unequip ===" << std::endl;
    hero->unequip(0);
    hero->unequip(1);
    hero->use(0, *enemy); // (unequipped)
    hero->use(1, *enemy); // (unequipped)
    hero->use(2, *enemy); 
    
    delete enemy;
    delete hero;
    delete src2;
    
    std::cout << "\n=== Test 4: Unknown materia ===" << std::endl;
    IMateriaSource* src3 = new MateriaSource();
    src3->learnMateria(new Ice());
    AMateria* unknown = src3->createMateria("fire"); // Should return NULL
    if (!unknown)
        std::cout << "Unknown materia type returns NULL" << std::endl;
    
    delete src3;
    
    std::cout << "\n=== Test 5: Learn too many materias ===" << std::endl;
    IMateriaSource* src4 = new MateriaSource();
    src4->learnMateria(new Ice());
    src4->learnMateria(new Cure());
    src4->learnMateria(new Ice());
    src4->learnMateria(new Cure());
    src4->learnMateria(new Ice()); // (source full)
    
    delete src4;
    
    return 0;
}