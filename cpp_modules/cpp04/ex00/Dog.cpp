/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:12:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/15 18:11:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound() const
{
	std::cout << "Dog sound **WOOF**." << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}

Dog &Dog::operator=(Dog const &rhs)
{
    this->type = rhs.type;
	return (*this);
}

Dog::Dog()
{
	std::cout << "Dog constructor called." << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

