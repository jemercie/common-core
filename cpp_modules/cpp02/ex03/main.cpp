/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:18:16 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/23 12:20:34 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point	a(1, 1);
	Point	b(2, 3);
	Point	c(5, 1);
	Point	p(2, 3.1);

	std::cout << "triangle : " << std::endl << std::endl;

	std::cout << "5            " << std::endl;
	std::cout << "4            " << std::endl;
	std::cout << "3    a       " << std::endl;
	std::cout << "2   .   .    " << std::endl;
	std::cout << "1  b   .   c " << std::endl;
	std::cout << "0            " << std::endl;
	std::cout << " 0 1 2 3 4 5 " << std::endl << std::endl;
	std::cout << " P(2, 3.1)" << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;

	Point	p1(2, 2);

	std::cout << " P(2, 2)" << std::endl;
	if (bsp(a, b, c, p1))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;

	Point	p2(2, 3);

	std::cout << " P(2, 3)" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;

	return (0);
}
