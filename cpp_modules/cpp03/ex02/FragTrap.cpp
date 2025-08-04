/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:35:50 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/10 12:41:44 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void    FragTrap::attack(const std::string & target)
{
    if (target.empty()){
            this->error(NO_TARGET, ""); return;
    }   
    if (this->_health == 0){ 
        this->error(IS_DEAD, "attack"); return ;
    }   
    if (this->_energy == 0)
    {   
        std::cout << "    ** FRAGTRAP " << this->_name << " has no more energy **" << std::endl;
        std::cout << "              - ATTACK FAILED -" << std::endl << std::endl;
        return ;
    }   

    this->_energy -= 1;

    std::cout << "    ** FRAGTRAP " << this->_name << RED << " ATTACKED " << WHITE << target << " **" << std::endl;
    std::cout << "       Causing - " << this->_ad << " - points of damage." << std::endl;
    std::cout << "--- " << this->_name << " have " << this->_energy << " energy points remaining ---" << std::endl << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << std::endl << "       HIGH FIVES REQUEST flemme" << std::endl << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
	this->_name = src._name;
	this->_energy = src._energy;
	this->_ad = src._ad;
	this->_health = src._health;
	return (*this);
}

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called." << std::endl;
	this->_health = 100;
	this->_energy = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor name called." << std::endl;
	this->_name = name;
	this->_health = 100;
	this->_energy = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(ScavTrap const & src)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
