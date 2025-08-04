/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:44:50 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/10 12:49:36 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

std::string DiamondTrap::getDiamondName() const
{
	return (this->_d_name);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is : " << this->_name << std::endl;
    std::cout << "My ClapTrap name is : " << this->_d_name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
	this->_d_name = src._d_name;
	this->_name = src._name;
	this->_energy = src._energy;
	this->_ad = src._ad;
	this->_health = src._health;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap name constructor called." << std::endl;
	this->_name = name;
	this->_d_name = _name + " diamond_trap";
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_ad = FragTrap::_ad;
/*
	std::cout << "diamondtrap ad : " << this->_ad << std::endl;
	std::cout << "fragtrap ad : " << FragTrap::_ad << std::endl;
	std::cout << "diamondtrap nrj : " << this->_energy << std::endl;
	std::cout << "scavtrap nrj : " << ScavTrap::_energy << std::endl;
	std::cout << "diamondtrap hitpts : " << this->_health << std::endl;
	std::cout << "fragtrap hitpts : " << FragTrap::_health << std::endl;
*/
}

DiamondTrap::DiamondTrap()
{
	this->_d_name = "diamond_trap";
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_ad = FragTrap::_ad;
	std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}
