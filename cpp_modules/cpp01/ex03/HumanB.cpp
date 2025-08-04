/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:16:22 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/19 16:13:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (this->weapon == NULL)
		std::cout << this->getName() << " doesn't have a weapon." << std::endl;
	else
		std::cout << this->getName() << " attacks with their " << this->weapon->getType() << std::endl;
}

std::string const &HumanB::getName() const
{
	return (this->_name);
}

void	HumanB::setWeapon(Weapon *wweapon)
{
	this->weapon = wweapon;
	return;
}

HumanB::HumanB(std::string name) : weapon(NULL), _name(name)
{
}

HumanB::~HumanB()
{
}

