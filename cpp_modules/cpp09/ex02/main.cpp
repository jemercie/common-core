/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:28:50 by jemercie          #+#    #+#             */
/*   Updated: 2023/12/04 11:45:45 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::cout << "Only 1 number, nothing to sort" << std::endl;
		return (0);
	}
	try{
		PmergeMe pmergeme(argc, argv);
	}
	catch(std::exception &err)
	{
		std::cout << err.what();
	}

	return (0);
}
