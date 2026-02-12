/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2026/02/03 12:38:55 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	int					fx;
	static const int	fr = 8;

	public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(const Fixed &src); //copy constructor
	Fixed &operator=(const Fixed &src); //copy assignment operator
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const ; //convert fixed to float
	int toInt(void) const; //convert float to int
};

std::ostream& operator<<(std::ostream& str, const Fixed& obj);

#endif

