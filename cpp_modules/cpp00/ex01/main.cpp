/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:33:20 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/12 10:14:41 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int	input_compare(PhoneBook &pbook, std::string buff);
static int	check_exit();

int main(void)
{
	std::string	buff;
	PhoneBook	pbook;

	std::cout << "You can ADD, SEARCH for a contact or EXIT." << std::endl;
	std::cout << " > ";
	while(std::getline(std::cin, buff))
	{
		if (input_compare(pbook, buff) < 0)
			return (0);
		std::cout << "> ";
	}
	return (0);
}

static int	input_compare(PhoneBook &pbook, std::string buff)
{
	if (buff.compare("ADD") == 0)
	{
		pbook.ADD();
		return (0);
	}
	else if (buff.compare("SEARCH") == 0)
	{
		pbook.SEARCH();
		return (0);
	}
	else if (buff.compare("EXIT") == 0)
	{
		if (check_exit() < 0)
			return (-1);
		return (0);
	}
	else
	{
		std::cout << "Wrong input. Type - ADD to add a contact" << std::endl;
		std::cout << "                   - SEARCH to display a contact" << std::endl;
		std::cout << "                   - EXIT to exit the phonebook" << std::endl;
	}
	return (0);
}

static int	check_exit()
{
	std::string	buff;

	std::cout << "Are you sure you want to leave? You'll lose all your contacts [ yes / no ] : ";
	std::getline(std::cin, buff);

	if (buff.compare("yes") == 0)
		return (-1);
	std::cout << "  * Type \" EXIT \" and \" yes \" if you want to exit the PhoneBook *" << std::endl;
	return (0);
}

