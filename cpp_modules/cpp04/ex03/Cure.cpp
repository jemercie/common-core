/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:41:06 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 16:38:29 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

void Cure::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure());
}

Cure &Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
	{
		this->_type	= rhs._type;
		this->is_equiped = rhs.is_equiped;
	}
	return (*this);
}

Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(Cure const & src)
{
	*this = src;
}

Cure::~Cure()
{
}
