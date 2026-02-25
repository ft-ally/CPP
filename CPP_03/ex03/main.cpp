
#include "DiamondTrap.hpp"

#define RESET   "\033[0m"
#define GREEN    "\033[32m"
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
		std::cout << std::endl << GREEN << "Your move, cowboy!" << RESET << std::endl;
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
// 	DiamondTrap player(playerName);
// 	startGame(player);
// }


int main()
{
    std::cout << GREEN << "=== Test 1: DiamondTrap Constructor ===" << RESET << std::endl;
    DiamondTrap d1("Diammy");
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 2: DiamondTrap Copy Constructor ===" << RESET << std::endl;
    DiamondTrap d2(d1);
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 3: DiamondTrap Assignment ===" << RESET << std::endl;
    DiamondTrap d3("Mondy");
    d3 = d1;
    std::cout << std::endl;

	std::cout << GREEN << "=== Test 4: DiamondTrap Attributes ===" << RESET << std::endl;
    d1.getAttributes();
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 5: DiamondTrap Attack (ScavTrap's attack(bomb) + FragTrap's attack damage(30)) ===" << RESET << std::endl;
    d1.attack("Enemy");
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 6: DiamondTrap Take Damage ===" << RESET << std::endl;
    d1.takeDamage(30);
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 7: DiamondTrap Repair ===" << RESET << std::endl;
    d1.beRepaired(20);
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 8: Guard Gate (ScavTrap) ===" << RESET << std::endl;
    d1.guardGate();
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 9: High Five (FragTrap) ===" << RESET << std::endl;
    d1.highFiveGuys();
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 10: Who Am I ===" << RESET << std::endl;
    d1.whoAmI();
    std::cout << std::endl;

    std::cout << GREEN << "=== Destructors (reverse order) ===" << RESET << std::endl;
    return 0;
}