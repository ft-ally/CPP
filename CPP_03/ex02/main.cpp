
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#include <random>
#include <unistd.h>

std::string initiateStart()
{
	std::string name;
	std::cout << "________________________________" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "| Welcome to FragTrap Battle!!|" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "|_____________________________|" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter FragTrap Name: ";
	if (!std::getline(std::cin, name))
		exit(0) ;
	usleep(1000000);
	std::cout << "FragTrap " << name << " is ready for battle!" << std::endl;
	usleep(1000000);
	std::cout << "FragTrap Boss is ready for battle!" << std::endl;
	std::cout << "****FragTrap Boss HP: 200" << std::endl << std::endl;
	return (name);
}

int startGame(FragTrap &player)
{
	std::string enemy= "FragTrap Boss";
	int enemy_hp = 200;
	int amount = 1;

	while (1)
	{
		std::random_device rnd;
		std::uniform_int_distribution<int> gen{1, 10};
		int roll = gen(rnd);
		std::cout << "FragTrap Boss rolls " << roll << "!"
		<< std::endl;
		usleep(1000000);
		if (roll % 2 == 0)
		{
			if (!player.takeDamage(roll))
				break ;
		}
		else
		{
			std::cout << "FragTrap Boss hurts itself in confusion causing " << roll << " damage!" << std::endl;
			enemy_hp = enemy_hp-roll;
			if (enemy_hp < 1)
			{
				std::cout << "Ya killed him!! Yay!!" << std::endl << std::endl;
					return (0);
			}
			else
				std::cout << "****FragTrap Boss HP: " << enemy_hp << std::endl;
		}
		std::string input;
		usleep(1000000);
		std::cout << std::endl << "Your move, cowboy!" << std::endl;
		std::cout << "ATTACK | HEAL | HIGH FIVE | EXIT" << std::endl;
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
    std::cout << "=== Test 1: FragTrap Constructor ===" << std::endl;
    FragTrap frag1("Warrior");
    std::cout << std::endl;

    std::cout << "=== Test 2: FragTrap Copy Constructor ===" << std::endl;
    FragTrap frag2(frag1);
    std::cout << std::endl;

    std::cout << "=== Test 3: FragTrap Assignment ===" << std::endl;
    FragTrap frag3("Fighter");
    frag3 = frag1;
    std::cout << std::endl;

    std::cout << "=== Test 4: FragTrap Attack ===" << std::endl;
    frag1.attack("Enemy");
    std::cout << std::endl;

    std::cout << "=== Test 5: FragTrap Take Damage ===" << std::endl;
    frag1.takeDamage(30);
    std::cout << std::endl;

    std::cout << "=== Test 6: FragTrap Repair ===" << std::endl;
    frag1.beRepaired(20);
    std::cout << std::endl;

    std::cout << "=== Test 7: High Five Mode ===" << std::endl;
    frag1.highFiveGuys();
    std::cout << std::endl;

    std::cout << "=== Destructors (reverse order) ===" << std::endl;
    return 0;
}