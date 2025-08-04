/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:10:00 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/25 15:45:32 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const &Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}

Weapon::Weapon()
{
}

Weapon::Weapon(std::string newType)
{
	this->_type = newType;
}

Weapon::~Weapon()
{
}

