/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2026/02/03 13:39:34 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed()
{
	fx = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fx = num << fr;
}
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called"  << std::endl;
	this->fx = roundf(num * (1 << fr));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called"  << std::endl;
	*this = ref;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called"  << std::endl;
	if (this != &f)
		fx = f.fx;
	return (*this);
}


