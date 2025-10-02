/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:51:09 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/02 17:20:43 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Phonebook
{
	Contact	contacts[8];
	
	public:
		void Add(void);
		void Display(void);
		void Search(void);
};

class Contact
{
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
	
	public:
		Contact();
		void AddContact(void);
		void 
};