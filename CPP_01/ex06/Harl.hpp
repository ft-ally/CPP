/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:26:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 18:38:50 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define ORANGE  "\033[38;5;208m"

#include <string>

class Harl
{
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	
	public:
	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif