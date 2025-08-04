/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:56:10 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/12 10:27:39 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	do_it_again(void);
static void	second_try(std::string &buff, std::string str);
static int	check_phone_number(std::string buff);
static void	print_tab_field(std::string str);

void PhoneBook::ADD()
{
	std::string buff;

	if (this->index == 8)
		this->index = 0;
	std::cout << std::endl << " --- INPUT NEW CONTACT INFORMATIONS ---" << std::endl <<std::endl;

	std::cout << "      first-name : ";
	std::getline(std::cin, buff);
	if (buff.empty())
		second_try(buff, "first-name");
	if (buff.empty())
		return (do_it_again());
	else
		this->contact[this->index].setFirstName(buff);

	std::cout << "      last-name : ";
	std::getline(std::cin, buff);
	if (buff.empty())
		second_try(buff, "last-name");
	if (buff.empty())
		return (do_it_again());
	else
		this->contact[this->index].setLastName(buff);

	std::cout << "      nickname : ";
	std::getline(std::cin, buff);
	if (buff.empty())
		second_try(buff, "nickname");
	if (buff.empty())
		return (do_it_again());
	else
		this->contact[this->index].setNickname(buff);

	std::cout << "      phone number : ";
	std::getline(std::cin, buff);
	if (buff.empty())
		second_try(buff, "phone number");
	if (buff.empty())
		return (do_it_again());
	if (check_phone_number(buff) < 0)
	{
		std::cout << " ** The phone number must contain numbers only **" << std::endl;
		std::cout << "      phone number : ";
		std::getline(std::cin, buff);
		if (buff.empty())
			return (do_it_again());		
	}
	if (check_phone_number(buff) < 0)
	{
		std::cout << "             ** NUMBERS ** ehh " << std::endl;
		std::cout << "         Type ADD to add a new contact." << std::endl;
		return ;
	}
	else
		this->contact[this->index].setPhoneNumber(buff);

	std::cout << "      darkest secret : ";
	std::getline(std::cin, buff);
	if (buff.empty())
		second_try(buff, "darkest secret");
	if (buff.empty())
		return (do_it_again());
	else
		this->contact[this->index].setDarkestSecret(buff);

	std::cout << std::endl << "  --- NEW CONTACT *" <<this->contact[this->index].getFirstName() << "* CREATED ---" << std::endl;
	this->index++;
	if (this->nb < 8)
		this->nb++;
	return ;
}

void	PhoneBook::SEARCH()
{
	int i = 0;
	std::string buff;

	std::cout << "           ----- CONTACTS -----" << std::endl << std::endl;
	if (this->nb == 0)
	{
		std::cout << "              ** NO ENTRY **" << std::endl;
		std::cout << "      Type ADD to add a new contact." << std::endl << std::endl;
		return;
	}
	std::cout << std::setw(43) << "   INDEX  |FIRST NAME|LAST  NAME| NICKNAME " << std::endl;
	std::cout << " - - - - -| - - - - -| - - - - -| - - - - -" << std::endl;
	while (i < this->nb)
	{
		std::cout << std::setw(10) << (i + 1) << "|";
		print_tab_field(this->contact[i].getFirstName());
		std::cout << "|";
		print_tab_field(this->contact[i].getLasttName());
		std::cout << "|";
		print_tab_field(this->contact[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << "Choose an index between 1 and " << this->nb << " to display the contact" << std::endl << "> ";
	std::getline(std::cin, buff);
	i = std::atoi(buff.c_str());
	if (i > 0 && i - 1 < this->nb)
	{
		std::cout << "          * " << this->contact[i - 1].getNickname() << " *" << std::endl << std::endl;
		std::cout << "     INDEX     : " << i << std::endl;
		std::cout << "  FIRST NAME   : " << this->contact[i - 1].getFirstName() << std::endl;
		std::cout << "   LAST NAME   : " << this->contact[i - 1].getLasttName() << std::endl;
		std::cout << "    NICKNAME   : " << this->contact[i - 1].getNickname() << std::endl;
		std::cout << " PHONE NUMBER  : " << this->contact[i - 1].getPhoneNumber() << std::endl;
		std::cout << "DARKEST SECRET : " << this->contact[i - 1].getDarkestSecret() << std::endl << std::endl;
	}
	else
		std::cout << std::endl << "            ** WRONG INDEX ** " << std::endl;
	std::cout << "You can ADD, SEARCH for a contact or EXIT" << std::endl;
}

PhoneBook::PhoneBook()
{
	index = 0;
	nb = 0;
	return;
}

PhoneBook::~PhoneBook()
{
	return;
}


static void	print_tab_field(std::string str)
{
	int len = str.length();

	if (len > 10)
	{
		str.resize(9);
		str += '.';
		std::cout << std::setw(10) << str;
		return ;
	}
	std::cout << std::setw(10) << str;
	return ;
}

static int check_phone_number(std::string buff)
{
	regex_t	regex;
	const char 	*str = buff.c_str();
	int 	check;

	check = regcomp(&regex, "^[0-9]*$", 0);
	int res = regexec(&regex, str, (size_t) 0, NULL, 0);
	regfree(&regex);
	if (res != 0)
		return (-1);
	return (0);
}
static void do_it_again(void)
{
    std::cout << "You can't leave a field empty. Type ADD to do it again." << std::endl;
    return;
}

static void	second_try(std::string &buff, std::string str)
{
	std::cout << " *** You have to input a " << str << " ***" << std::endl;
	std::cout << "      " << str << " : ";
	std::getline(std::cin, buff);
}
