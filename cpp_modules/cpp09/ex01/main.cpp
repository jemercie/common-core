/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:37 by jemercie          #+#    #+#             */
/*   Updated: 2023/12/02 15:55:29 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong args, you can try with \"3 3 + 3 /\"." << std::endl;
		return (0);
	}
	try
	{
		RPN	rpn(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}
