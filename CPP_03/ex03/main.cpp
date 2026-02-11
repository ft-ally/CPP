
#include "DiamondTrap.hpp"

#include <random>
#include <unistd.h>

std::string initiateStart()
{
	std::string name;
	std::cout << "________________________________" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "| Welcome to D-Trap Battle!!  |" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "|_____________________________|" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter D-Trap Name: ";
	if (!std::getline(std::cin, name))
		exit(0) ;
	usleep(1000000);
	std::cout << "D-Trap " << name << " is ready for battle!" << std::endl;
	usleep(1000000);
	std::cout << "D-Trap Boss is ready for battle!" << std::endl;
	std::cout << "****D-Trap Boss HP: 200" << std::endl << std::endl;
	return (name);
}

int startGame(DiamondTrap &player)
{
	std::string enemy= "D-Trap Boss";
	int enemy_hp = 200;
	int amount = 1;

	while (1)
	{
		std::random_device rnd;
		std::uniform_int_distribution<int> gen{1, 10};
		int roll = gen(rnd);
		std::cout << "D-Trap Boss rolls " << roll << "!"
		<< std::endl;
		usleep(1000000);
		if (roll % 2 == 0)
		{
			if (!player.takeDamage(roll))
				break ;
		}
		else
		{
			std::cout << "D-Trap Boss hurts itself in confusion causing " << roll << " damage!" << std::endl;
			enemy_hp = enemy_hp-roll;
			if (enemy_hp < 1)
			{
				std::cout << "Ya killed him!! Yay!!" << std::endl << std::endl;
					return (0);
			}
			else
				std::cout << "****D-Trap Boss HP: " << enemy_hp << std::endl;
		}
		std::string input;
		usleep(1000000);
		std::cout << std::endl << "Your move, cowboy!" << std::endl;
		std::cout << "ATTACK | HEAL | HIGH FIVE | GUARD | DOUBT EXISTENCE | EXIT" << std::endl;
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
		else if (input == "high five" || input == "HIGH FIVE")
			player.highFiveGuys();
		else if (input == "guard" || input == "GUARD")
			player.guardGate();
		else if (input == "doubt" || input == "DOUBT")
			player.whoAmI();
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
// 	FragTrap player(playerName);
// 	startGame(player);
// }
int main()
{
    std::cout << "=== Test 1: DiamondTrap Constructor ===" << std::endl;
    DiamondTrap diamond1("Warrior");
    std::cout << std::endl;

    std::cout << "=== Test 2: DiamondTrap Copy Constructor ===" << std::endl;
    DiamondTrap diamond2(diamond1);
    std::cout << std::endl;

    std::cout << "=== Test 3: DiamondTrap Assignment ===" << std::endl;
    DiamondTrap diamond3("Fighter");
    diamond3 = diamond1;
    std::cout << std::endl;

    std::cout << "=== Test 4: DiamondTrap Attack (ScavTrap) ===" << std::endl;
    diamond1.attack("Enemy");
    std::cout << std::endl;

    std::cout << "=== Test 5: DiamondTrap Take Damage ===" << std::endl;
    diamond1.takeDamage(30);
    std::cout << std::endl;

    std::cout << "=== Test 6: DiamondTrap Repair ===" << std::endl;
    diamond1.beRepaired(20);
    std::cout << std::endl;

    std::cout << "=== Test 7: Guard Gate (ScavTrap) ===" << std::endl;
    diamond1.guardGate();
    std::cout << std::endl;

    std::cout << "=== Test 8: High Five (FragTrap) ===" << std::endl;
    diamond1.highFiveGuys();
    std::cout << std::endl;

    std::cout << "=== Test 9: Who Am I ===" << std::endl;
    diamond1.whoAmI();
    std::cout << std::endl;

    std::cout << "=== Destructors (reverse order) ===" << std::endl;
    return 0;
}