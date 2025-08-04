/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:06:27 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/20 15:11:37 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int intTab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string stringTab[10] = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj"};
	std::cout << "intTab : "; 
	for (int i = 0; i < 10; i++){
		std::cout << intTab[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "stringTab : "; 
	for (int i = 0; i < 10; i++){
		std::cout << stringTab[i] << " ";
	}
	std::cout << std::endl;

	iter(intTab, 10, clearInt);
	iter(stringTab, 10, clearStr);

	std::cout << "intTab : "; 
	for (int i = 0; i < 10; i++){
		std::cout << intTab[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "stringTab : "; 
	for (int i = 0; i < 10; i++){
		std::cout << stringTab[i] << " ";
	}
	return (0);
}
