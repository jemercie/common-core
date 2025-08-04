/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:44:24 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/20 15:05:29 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	std::cout << "initial values : a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "swap ( a, b )  : a = " << a << ", b = " << b << std::endl;
	std::cout << "min ( a, b ) : " << ::min( a, b ) << std::endl;
	std::cout << "max ( a, b ) : " << ::max( a, b ) << std::endl << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "initial values : c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "swap ( c, d )  : c = " << c << ", d = " << d << std::endl;
	std::cout << "min ( c, d ) : " << ::min( c, d ) << std::endl;
	std::cout << "max ( c, d ) : " << ::max( c, d ) << std::endl;
	return 0;
}


