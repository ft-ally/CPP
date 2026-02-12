
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#include <iostream>

int main()
{
	std::cout << RED << " ======== SUBJECT TESTS ======== " << RESET << std::endl;

	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl << std::endl;
	
	delete j;//should not create a leak
	std::cout << std::endl;
	delete i;
	
	std::cout << std::endl << std::endl;
	std::cout << GREEN << "================== TESTS =====================" << RESET << std::endl;


	std::cout << RED << "======== TEST 1: Default constructors ========" << RESET << std::endl;
	
	Animal *Animals[4];
	for (int i = 0; i < 4; i++)
	{
		std::cout << BLUE << "Creating animal...." << RESET << std::endl;
		if (i < 2)
		{
			Animals[i] = new Dog();
			std::cout << GREEN << "DOG " << i + 1 << " CREATED!" << std::endl;
			Animals[i]->makeSound();
			std::cout << RESET; 
			Animals[i]->sayIdeas();
			std::cout << std::endl << std::endl;

		}
		else
		{
			Animals[i] = new Cat();
			std::cout << GREEN << "CAT " << i - 2 + 1 << " CREATED!" << std::endl;
			Animals[i]->makeSound();
			std::cout << RESET; 
			Animals[i]->sayIdeas();
			std::cout << std::endl << std::endl;
		}
	}
	std::cout << RED << "======== TEST 2: Default deconstructors ========" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete (Animals[i]);
		std::cout << GREEN << "ANIMAL " << i + 1 << " DELETED!" << RESET << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << RED << "========= TEST 3: Constructor with parameter======" << RESET << std::endl;
	
	Animal *newAnimals[4];
	for (int i = 0; i < 4; i++)
	{
		std::cout << BLUE << "Creating animal...." << RESET << std::endl;
		if (i < 2)
		{
			newAnimals[i] = new Dog("treats (dog thoughts)");
			std::cout << GREEN << "DOG " << i + 1 << " CREATED!"<< std::endl;
			newAnimals[i]->makeSound();
			std::cout << RESET; 
			newAnimals[i]->sayIdeas();
			std::cout << std::endl << std::endl;
		}
		else
		{
			newAnimals[i] = new Cat("world domination (cat thoughts)");
			std::cout << GREEN << "CAT " << i - 2 + 1 << " CREATED!" << std::endl;
			newAnimals[i]->makeSound();
			std::cout << RESET; 
			newAnimals[i]->sayIdeas();
			std::cout << std::endl << std::endl;
		}
	}
	std::cout << RED << " ======== TEST 4: Default deconstructors ======== " << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete (newAnimals[i]);
		std::cout << GREEN << "ANIMAL " << i + 1 << " DELETED!" << RESET << std::endl << std::endl;
	}
	std::cout << RED << "======== TEST 5: Copy constructors ========" << RESET << std::endl;
	Dog *doggie = new Dog("I am the real dog");
	std::cout << GREEN << "REAL DOG CREATED!"<< RESET << std::endl;
	doggie->sayIdeas();
	std::cout << std::endl << std::endl;
	Dog fakeDoggie(*doggie); //on stack no del
	std::cout << GREEN << "FAKE DOG CREATED!"<< RESET << std::endl;
	fakeDoggie.sayIdeas();
	
	std::cout << std::endl << std::endl;
	
	std::cout << BLUE << "Modifying real dog's brain..." << RESET << std::endl;
	doggie->plantIdeas("hehehe");
	
	std::cout << YELLOW << "Real dog ideas after modification:" << RESET << std::endl;
	doggie->sayIdeas();
	
	std::cout << YELLOW << "Copied fake dog ideas (unchanged if deep copy):" << RESET << std::endl;
	fakeDoggie.sayIdeas();
	delete doggie;
	return (0);
}

