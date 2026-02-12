
#include "AAnimal.hpp"
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
	// AAnimal();
	std::cout << RED << " ======== SUBJECT TESTS ======== " << RESET << std::endl;

	const AAnimal* j = new Dog();
	std::cout << BLUE << "Animal is a " << j->getType() << RESET << std::endl;
	std::cout << std::endl;
	const AAnimal* i = new Cat();
	std::cout << BLUE << "Animal is a " << i->getType() << RESET << std::endl;
	
	std::cout << std::endl << std::endl;
	
	delete j;//should not create a leak
	std::cout << std::endl;
	delete i;
	
	std::cout << std::endl << std::endl;
	std::cout << GREEN << "================== TESTS =====================" << RESET << std::endl;


	std::cout << RED << "======== TEST 1: Default constructors ========" << RESET << std::endl;
	
	AAnimal *AAnimals[4];
	for (int i = 0; i < 4; i++)
	{
		std::cout << BLUE << "Creating AAnimal...." << RESET << std::endl;
		if (i < 2)
		{
			AAnimals[i] = new Dog();
			std::cout << GREEN << "DOG " << i + 1 << " CREATED!" << std::endl;
			AAnimals[i]->makeSound();
			std::cout << RESET; 
			AAnimals[i]->sayIdeas();
			std::cout << std::endl << std::endl;

		}
		else
		{
			AAnimals[i] = new Cat();
			std::cout << GREEN << "CAT " << i - 2 + 1 << " CREATED!" << std::endl;
			AAnimals[i]->makeSound();
			std::cout << RESET; 
			AAnimals[i]->sayIdeas();
			std::cout << std::endl << std::endl;
		}
	}
	std::cout << RED << "======== TEST 2: Default deconstructors ========" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete (AAnimals[i]);
		std::cout << GREEN << "AAnimal " << i + 1 << " DELETED!" << RESET << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << RED << "========= TEST 3: Constructor with parameter======" << RESET << std::endl;
	
	AAnimal *newAAnimals[4];
	for (int i = 0; i < 4; i++)
	{
		std::cout << BLUE << "Creating AAnimal...." << RESET << std::endl;
		if (i < 2)
		{
			newAAnimals[i] = new Dog("treats (dog thoughts)");
			std::cout << GREEN << "DOG " << i + 1 << " CREATED!"<< std::endl;
			newAAnimals[i]->makeSound();
			std::cout << RESET; 
			newAAnimals[i]->sayIdeas();
			std::cout << std::endl << std::endl;
		}
		else
		{
			newAAnimals[i] = new Cat("world domination (cat thoughts)");
			std::cout << GREEN << "CAT " << i - 2 + 1 << " CREATED!" << std::endl;
			newAAnimals[i]->makeSound();
			std::cout << RESET; 
			newAAnimals[i]->sayIdeas();
			std::cout << std::endl << std::endl;
		}
	}
	std::cout << RED << " ======== TEST 4: Default deconstructors ======== " << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete (newAAnimals[i]);
		std::cout << GREEN << "AAnimal " << i + 1 << " DELETED!" << RESET << std::endl << std::endl;
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

