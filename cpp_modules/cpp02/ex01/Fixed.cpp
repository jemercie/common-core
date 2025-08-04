/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:58:41 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/23 11:36:33 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

int Fixed::getRawBits(void) const
{
	return (this->_nb);
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->_nb = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(const int nb)
{
	setRawBits(nb << this->_fracBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb)
{
	this->_nb = roundf(nb * (1 << this->_fracBits));
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float) this->_nb / (1 << this->_fracBits));
}

int Fixed::toInt(void) const
{
	return (this->_nb >> this->_fracBits);
}

Fixed::Fixed()
{
	this->_nb = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Fixed  const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
