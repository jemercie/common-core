/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:03:56 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/12 10:11:25 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() const
{
	return (this->first_name);
}

std::string Contact::getLasttName() const
{
	return (this->last_name);
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phone_number);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkest_secret);
}

void	Contact::setFirstName(std::string buf)
{
	this->first_name = buf;
	return;
}

void	Contact::setLastName(std::string buf)
{
	this->last_name = buf;
	return;
}

void	Contact::setNickname(std::string buf)
{
	this->nickname = buf;
	return;
}

void	Contact::setPhoneNumber(std::string buf)
{
	this->phone_number = buf;
	return;
}

void	Contact::setDarkestSecret(std::string buf)
{
	this->darkest_secret = buf;
	return;
}


Contact::Contact()
{
	return;
}

Contact::~Contact()
{
	return;
}
