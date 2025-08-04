/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:39:28 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 16:38:02 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

void Ice::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

Ice &Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
	{
		this->_type	= rhs._type;
		this->is_equiped = rhs.is_equiped;
	}
	return (*this);
}

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(Ice const & src)
{
	*this = src;
}

Ice::~Ice()
{
}
