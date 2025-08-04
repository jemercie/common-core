/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:12:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/02 10:17:25 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

void	AAnimal::makeSound() const
{
	std::cout << "Animal sound krr." << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

AAnimal::AAnimal()
{
	std::cout << "Animal constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}
AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called." << std::endl;
}

