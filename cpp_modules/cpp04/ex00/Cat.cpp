/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:12:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/15 18:10:12 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound() const
{
	std::cout << "Cat sound **MEOW**." << std::endl;
}

std::string Cat::getType() const
{
	return (this->type);
}

Cat &Cat::operator=(Cat const &rhs)
{
    this->type = rhs.type;
	return (*this);
}

Cat::Cat()
{
	std::cout << "Cat constructor called." << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const & src)
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

