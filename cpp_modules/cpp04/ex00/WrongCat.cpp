/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:12:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/28 16:09:24 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sound **MEOW**." << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->type);
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called." << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = src;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

