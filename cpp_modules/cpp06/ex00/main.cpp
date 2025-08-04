/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:14:10 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/08 10:21:44 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int WrongArg();

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (WrongArg());
	try{
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &err)
	{
		std::cout << err.what();
	}
	return 0;
}


static int WrongArg()
{
	std::cout << "Wrong argument. " << std::endl;
	return 0;
}
