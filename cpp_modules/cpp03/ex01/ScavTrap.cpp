/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:35:50 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/10 12:20:16 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void    ScavTrap::attack(const std::string & target)
{
    if (target.empty()){
            this->error(NO_TARGET, ""); return;
    }   
    if (this->_health == 0){ 
        this->error(IS_DEAD, "attack"); return ;
    }   
    if (this->_energy == 0)
    {   
        std::cout << "    ** SCAVTRAP " << this->_name << " has no more energy **" << std::endl;
        std::cout << "              - ATTACK FAILED -" << std::endl << std::endl;
        return ;
    }   

    this->_energy -= 1;

    std::cout << "    ** SCAVTRAP " << this->_name << RED << " ATTACKED " << WHITE << target << " **" << std::endl;
    std::cout << "     Causing - " << this->_ad << " - points of damage." << std::endl;
    std::cout << "--- " << this->_name << " have " << this->_energy << " energy points remaining ---" << std::endl << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << std::endl << "Guard gate display a message informing that ScavTrap is now in Gatekeeper mode" << std::endl << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
	this->_name = src._name;
	this->_energy = src._energy;
	this->_ad = src._ad;
	this->_health = src._health;
	return (*this);
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called." << std::endl;
	this->_health = 100;
	this->_energy = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor name called." << std::endl;
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
