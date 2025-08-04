/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:58:20 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/10 12:19:30 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void    ClapTrap::attack(const std::string & target)
{
	if (target.empty()){
			this->error(NO_TARGET, ""); return;
	}
	if (this->_health == 0){
		this->error(IS_DEAD, "attack"); return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "    ** ClapTrap " << this->_name << " has no more energy **" << std::endl;
		std::cout << "              - ATTACK FAILED -" << std::endl << std::endl;
		return ;
	}

	this->_energy -= 1;

	std::cout << "    ** ClapTrap " << this->_name << RED << " ATTACKED " << WHITE << target << " **" << std::endl;
	std::cout << "    Causing - " << this->_ad << " - points of damage." << std::endl;
	std::cout << "--- " << this->_name << " have " << this->_energy << " energy points remaining ---" << std::endl << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "    ** " << "Claptrap " << this->_name << " was " << RED << "ATTACKED" << WHITE << " **" << std::endl;

	if (this->_health <= 0)
	{
		std::cout << "          He is already dead !!" << std::endl << std::endl;
		return ;
	}

	std::cout << "          He took - " << amount << " - damage";
	this->_health -= amount;

	if (this->_health <= 0)
		std::cout << "." << std::endl << "               ** He DIED **" << std::endl << std::endl;
	else
		std::cout << std::endl << "--- He has - " << this->_health << " - remaining life points ---" << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_health <= 0){
		this->error(IS_DEAD, " be heal"); return ;
	}
	std::cout << "    ** ClapTrap " <<  this->_name << " has been " << GREEN << "HEALED" << WHITE " **" << std::endl;

	this->_health += amount;

	std::cout << "--- He has now - " << this->_health << " - life points remaining ---" << std::endl << std::endl;
}

void	ClapTrap::error(int ERR, std::string str)
{
	if (ERR == IS_DEAD)
		std::cout << "** Claptrap " << this->_name << " can't " << str << ", he's dead! **" << std::endl;
	else if (ERR == NO_TARGET)
		std::cout << "             *** No target!! ***" << std::endl << std::endl;

}

void	ClapTrap::setAD(unsigned int amount)
{
	this->_ad = amount;
}

void	ClapTrap::setNewName(std::string name)
{
	this->_name = name;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int	ClapTrap::getStats(int i) const
{
	if (i == HEALTH)
		return (this->_health);
	if (i == ENERGY)
		return (this->_energy);
	if (i == AD)
		return (this->_ad);
	return (0);
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
	this->_name = src._name;
	this->_energy = src._energy;
	this->_ad = src._ad;
	this->_health = src._health;
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor name called." << std::endl;
	this->_name = name;
	this->_health = 10;
	this->_energy = 10;
	this->_ad = 0;
}

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_health = 10;
	this->_energy = 10;
	this->_ad = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
