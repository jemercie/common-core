/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:12:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:40:42 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void	Animal::makeSound() const
{
	std::cout << "Animal sound krr." << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

Animal	&Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

Animal::Animal()
{
	std::cout << "Animal constructor called." << std::endl;
	this->type = "Animal";
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

