
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <random>
#include <unistd.h>

std::string initiateStart()
{
	std::string name;
	std::cout << "________________________________" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "| Welcome to ScavTrap Battle!!|" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "|_____________________________|" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter ScavTrap Name: ";
	if (!std::getline(std::cin, name))
		exit(0) ;
	usleep(1000000);
	std::cout << "ScavTrap " << name << " is ready for battle!" << std::endl;
	usleep(1000000);
	std::cout << "ScavTrap Boss is ready for battle!" << std::endl;
	std::cout << "****ScavTrap Boss HP: 200" << std::endl << std::endl;
	return (name);
}

int startGame(ScavTrap &player)
{
	std::string enemy= "ScavTrap Boss";
	int enemy_hp = 200;
	int amount = 1;

	while (1)
	{
		std::random_device rnd;
		std::uniform_int_distribution<int> gen{1, 10};
		int roll = gen(rnd);
		std::cout << "ScavTrap Boss rolls " << roll << "!"
		<< std::endl;
		usleep(1000000);
		if (roll % 2 == 0)
		{
			if (!player.takeDamage(roll))
				break ;
		}
		else
		{
			std::cout << "ScavTrap Boss hurts itself in confusion causing " << roll << " damage!" << std::endl;
			enemy_hp = enemy_hp-roll;
			if (enemy_hp < 1)
			{
				std::cout << "Ya killed him!! Yay!!" << std::endl << std::endl;
					return (0);
			}
			else
				std::cout << "****ScavTrap Boss HP: " << enemy_hp << std::endl;
		}
		std::string input;
		usleep(1000000);
		std::cout << std::endl << "Your move, cowboy!" << std::endl;
		std::cout << "ATTACK | HEAL | GUARD | EXIT" << std::endl;
		if (!std::getline(std::cin, input))
			exit(0) ;
		else if (input == "ATTACK" || input == "attack")
		{
			player.attack(enemy);
			enemy_hp -= player.getDamage();
			if (enemy_hp < 1)
			{
				std::cout << "Ya killed him!! Yay!!" << std::endl;
					return (0);
			}
		}
		else if (input == "HEAL" || input == "heal")
			player.beRepaired(amount);
		else if (input == "GUARD" || input == "guard")
			player.guardGate();
		else if (input == "EXIT" || input == "exit")
			break ;
		else
			std::cout << "Wrong move!!" << std::endl;
	
	}
	return (0);
}

// int main()
// {
// 	std::string playerName = initiateStart();
// 	ScavTrap player(playerName);
// 	startGame(player);
// }

int main()
{
    std::cout << "=== Test 1: ScavTrap Constructor ===" << std::endl;
    ScavTrap scav1("Warrior");
    std::cout << std::endl;

    std::cout << "=== Test 2: ScavTrap Copy Constructor ===" << std::endl;
    ScavTrap scav2(scav1);
    std::cout << std::endl;

    std::cout << "=== Test 3: ScavTrap Assignment ===" << std::endl;
    ScavTrap scav3("Fighter");
    scav3 = scav1;
    std::cout << std::endl;

    std::cout << "=== Test 4: ScavTrap Attack ===" << std::endl;
    scav1.attack("Enemy");
    std::cout << std::endl;

    std::cout << "=== Test 5: ScavTrap Take Damage ===" << std::endl;
    scav1.takeDamage(30);
    std::cout << std::endl;

    std::cout << "=== Test 6: ScavTrap Repair ===" << std::endl;
    scav1.beRepaired(20);
    std::cout << std::endl;

    std::cout << "=== Test 7: Guard Gate Mode ===" << std::endl;
    scav1.guardGate();
    std::cout << std::endl;

    std::cout << "=== Destructors (reverse order) ===" << std::endl;
    return 0;
}