/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:15:00 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/19 16:12:05 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->getName() << " attacks with their " << this->weapon.getType() << std::endl;
}

std::string const &HumanA::getName() const
{
	return(this->_name);
}

HumanA::HumanA(std::string name, Weapon &newWeapon) : weapon(newWeapon), _name(name)
{
}

HumanA::~HumanA()
{
}
