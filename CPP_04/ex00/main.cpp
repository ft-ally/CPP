
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>


int main()
{
	std::cout << " ======== SUBJECT TESTS ======== " << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl << std::endl;
	
	std::cout << " ================ TESTS ============== " << std::endl;
	std::cout << " ======== Constructors called ======== " << std::endl;
	const Animal* animalTest = new Animal();
	std::cout << std::endl;
	const Animal* doggie = new Dog();
	std::cout << std::endl;
	const Animal* kitty = new Cat();
	std::cout << std::endl;
	const WrongAnimal* wrongAnimalTest = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* wrongKitty = new WrongCat();
	std::cout << std::endl;
	
	std::cout << " =====Test 1: Calling Animal Base Class =======" << std::endl;
	std::cout << "Type: " << animalTest->getType() << std::endl;
	std::cout << "Sound: "; 
	animalTest->makeSound(); 
	std::cout << std::endl;
	
	std::cout << " =====Test 2: Calling Dog Derived Base Class ========" << std::endl;
	std::cout << "Type: " << doggie->getType() << std::endl;
	std::cout << "Sound: "; 
	doggie->makeSound(); 
	std::cout << std::endl;
	
	
	std::cout << " =====Test 3: Calling Cat Derived Base Class ========" << std::endl;
	std::cout << "Type: " << kitty->getType() << std::endl;
	std::cout << "Sound: "; 
	kitty->makeSound();
	std::cout << std::endl;
	
	
	std::cout << " =====Test 4: Calling WrongAnimal Base Class =========" << std::endl;
	std::cout << "Type: " << wrongAnimalTest->getType() << std::endl;
	std::cout << "Sound: "; 
	wrongAnimalTest->makeSound(); 
	std::cout << std::endl;
	
	
	std::cout << " =====Test 5: Calling WrongCat Derived Base Class ========" << std::endl;
	std::cout << "Type: " << wrongKitty->getType() << std::endl;
	std::cout << "Sound: "; 
	wrongKitty->makeSound();
	std::cout << std::endl;
	
	std::cout << " ======== Deconstructors called ======== " << std::endl;
	delete animalTest;
	std::cout << std::endl;
	delete doggie;
	std::cout << std::endl;
	delete kitty;
	std::cout << std::endl;
	delete wrongAnimalTest;
	std::cout << std::endl;
	delete wrongKitty;

	return 0;
}

