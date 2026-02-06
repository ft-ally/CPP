/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2026/02/03 13:21:54 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main() 
{
	Point a(2, 3);
	Point b(3, -4);
	Point c(-2, -2);
	
	Point point1(-6, -2);
	Point point2(1, -1);
	
	bool p1 = bsp(a, b, c, point1);
	bool p2 = bsp(a, b, c, point2);
	if (p1)
		std::cout << "Point 1 is inside triangle" << std::endl;
	else
		std::cout << "Point 1 is outside triangle" << std::endl;
	if (p2)
		std::cout << "Point 2 is inside triangle" << std::endl;
	else
		std::cout << "Point 2 is outside triangle" << std::endl;
	return (0);
}
