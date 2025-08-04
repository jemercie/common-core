/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:54:20 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/28 13:54:47 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	(void) argc;
	try
	{
		BitcoinExchange n1("data.csv", argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return(0);
}
