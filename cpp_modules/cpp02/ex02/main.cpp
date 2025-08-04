/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:18:16 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/25 19:19:40 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "increment/decrement operators : " << std::endl;
	std::cout << "        a :" << a << std::endl;
	std::cout << "      ++a : " << ++a << std::endl;
	std::cout << "        a : " << a << std::endl;
	std::cout << "      a++ : " << a++ << std::endl;
	std::cout << "        a : " << a << std::endl;
	
	std::cout << "      a-- : " << a-- << std::endl;
	std::cout << "        a : " << a << std::endl;
	std::cout << "      ++a : " << ++a << std::endl;
	std::cout << "        a : " << a << std::endl;
	std::cout << "      --a : " << --a << std::endl;
	std::cout << "        a : " << a << std::endl;
	std::cout << std::endl;

	std::cout << "min && maxxx :  entre  " << a << " et " << b << std::endl;
	std::cout << "      max : " << Fixed::max( a, b ) << std::endl;
	std::cout << "      min : " << Fixed::min( a, b ) << std::endl;
	std::cout << std::endl;

	std::cout << "arithmetic operators: " << std::endl;
	std::cout << "   * + *  : 2 + 1 = " << 2 + 1 << std::endl;
	std::cout << "   * - *  : 2 - 1 = " << 2 - 1 << std::endl;
	std::cout << "   * * *  : 2 * 4 = " << 2 * 4 << std::endl;
	std::cout << "   * / *  : 6 / 2 = " << 6 / 2 << std::endl;
	std::cout << std::endl;

	std::cout << "comparison operators: ( 0 -> no, 1 -> yes)" << std::endl;
	std::cout << " is 4 > 6  ? " << (4 > 6) << std::endl;
	std::cout << " is 4 > 4  ? " << (4 > 4) << std::endl;
	std::cout << " is 4 >= 4 ? " << (4 >= 4) << std::endl;
	std::cout << " is 4 < 6  ? " << (4 < 6) << std::endl;
	std::cout << " is 4 < 4  ? " << (4 < 4) << std::endl;
	std::cout << " is 4 <= 4 ? " << (4 <= 4) << std::endl;
	std::cout << " is 4 != 6 ? " << (4 != 6) << std::endl;
	std::cout << " is 3 != 3 ? " << (3 != 3) << std::endl;
	std::cout << " is 3 == 3 ? " << (3 == 3) << std::endl;
	std::cout << " is 4 == 6 ? " << (4 == 6) << std::endl;

	return (0);
}
