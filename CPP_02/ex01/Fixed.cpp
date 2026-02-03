/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 13:54:47 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


Fixed::Fixed()
{
	fx = 0;
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	this->fx = num << fr;
}
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	this->fx = roundf(num * (1 << fr));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called\n";
	fx = ref.fx;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &f)
		fx = f.fx;
	return (*this);
}

float Fixed::toFloat(void) const
{
	return ((float)fx / (1 << fr));
}

int Fixed::toInt(void) const
{
	return ((int)fx >> fr);
}

std::ostream &operator<<(std::ostream& os, const Fixed& num)
{
	os << num.toFloat();
	return (os);
}
