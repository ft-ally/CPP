/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 13:54:35 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;5;208m"

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif