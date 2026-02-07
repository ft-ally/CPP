
#include "ClapTrap.hpp"

#include <random>
#include <iostream>
#include <unistd.h>

std::string initiateStart()
{
	std::string name;
	std::cout << "________________________________" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "| Welcome to ClapTrap Battle!!|" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "|_____________________________|" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter ClapTrap Name: ";
	if (!std::getline(std::cin, name))
		exit(0) ;
	usleep(1000000);
	std::cout << "ClapTrap " << name << " is ready for battle!" << std::endl;
	usleep(1000000);
	std::cout << "ClapTrap Boss is ready for battle!" << std::endl;
	std::cout << "****ClapTrap Boss HP: 100" << std::endl << std::endl;
	return (name);
}

int startGame(ClapTrap &player)
{
	std::string enemy= "ClapTrap Boss";
	int enemy_hp = 100;
	int amount = 1;

	while (1)
	{
		std::random_device rnd;
		std::uniform_int_distribution<int> gen{1, 10};
		int roll = gen(rnd);
		std::cout << "ClapTrap Boss rolls " << roll << "!"
		<< std::endl;
		usleep(1000000);
		if (roll % 2 == 0)
		{
			if (!player.takeDamage(roll))
				break ;
		}
		else
		{
			std::cout << "ClapTrap Boss hurts itself in confusion causing " << roll << " damage!" << std::endl;
			enemy_hp = enemy_hp-roll;
			if (enemy_hp < 1)
			{
				std::cout << "Ya killed him!! Yay!!" << std::endl << std::endl;
					return (0);
			}
			else
				std::cout << "****ClapTrap Boss HP: " << enemy_hp << std::endl;
		}
		std::string input;
		usleep(1000000);
		std::cout << std::endl << "Your move, cowboy!" << std::endl;
		std::cout << "ATTACK | HEAL | EXIT" << std::endl;
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
// 	ClapTrap player(playerName);
// 	startGame(player);
// }


int main()
{
	std::cout << "Default Constructor" << std::endl;
    ClapTrap player1("Robot1");
    std::cout << std::endl;

    std::cout << "=== Test 2: Copy Constructor ===" << std::endl;
    ClapTrap player2(player1);
    std::cout << std::endl;

    std::cout << "=== Test 3: Copy Assignment ===" << std::endl;
    ClapTrap player3("Robot3");
    player3 = player1;
    std::cout << std::endl;

    std::cout << "=== Test 4: Attack ===" << std::endl;
    player1.attack("Target");
    std::cout << std::endl;

    std::cout << "=== Test 5: Take Damage ===" << std::endl;
    player1.takeDamage(3);
    std::cout << std::endl;

    std::cout << "=== Test 6: Be Repaired ===" << std::endl;
    player1.beRepaired(5);
    std::cout << std::endl;

    std::cout << "=== Test 7: Run out of energy ===" << std::endl;
    for (int i = 0; i < 11; i++)
        player1.attack("Enemy");
    std::cout << std::endl;

    std::cout << "=== Test 8: Die ===" << std::endl;
    player2.takeDamage(15);
    player2.attack("Enemy");
    std::cout << std::endl;

    std::cout << "=== Destructors ===" << std::endl;
    return 0;
}
