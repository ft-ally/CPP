/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:51:09 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/20 13:09:07 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
	Contact	contacts[8];
	int		count;
	int		oldest;
	public:
		PhoneBook();
		void add(void);
		void search(void);
		void printOverview();
		void printContact(int i);
};

#endif