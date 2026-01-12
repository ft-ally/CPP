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

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	int					fx;
	static const int	fr;

	public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &ref); //copy constructor
	Fixed &operator=(const Fixed &f); //copy assignment overload
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif

