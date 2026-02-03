/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2026/02/03 13:36:40 by aalombro         ###   ########.fr       */
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
	Fixed(const Fixed &ref); //copy constructor
	Fixed &operator=(const Fixed &f); //copy assignment operator
	
	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj);
	Fixed operator/(const Fixed &obj);
	
	static int &min(int &i, int &j); //(if &i < j , return (i) else return (j));
	static int &min (const int &i, const int &j);
	static int &max(int &i, int &j);
	static int &max (const int &i, const int &j);
};

std::ostream& operator<<(std::ostream& os, const Fixed& num);

#endif

