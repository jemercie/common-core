/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:58:41 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/23 12:09:08 by jemercie         ###   ########.fr       */
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
	if (this != &rhs)
		this->_nb = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

float	Fixed::operator+(Fixed const & rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

float	Fixed::operator-(Fixed const & rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

float	Fixed::operator*(Fixed const & rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

float	Fixed::operator/(Fixed const & rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	& Fixed::operator--()
{
	this->_nb--;
	return (*this);
}

Fixed	& Fixed::operator--(int)
{
	static Fixed tmp = *this;

	--this->_nb;
	return (tmp);
}

Fixed	& Fixed::operator++()
{
	this->_nb++;
	return (*this);
}

Fixed	& Fixed::operator++(int)
{
	static Fixed tmp = *this;

	++this->_nb;
	return (tmp);
}

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1.toFloat() <= nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

const Fixed &Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1.toFloat() <= nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1.toFloat() >= nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1.toFloat() >= nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

Fixed::Fixed(const int nb)
{
	this->_nb = nb << this->_fracBits;
}

Fixed::Fixed(const float nb)
{
	this->_nb = roundf(nb * (1 << this->_fracBits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_nb / (float)(1 << this->_fracBits));
}

int Fixed::toInt(void) const
{
	return (roundf(this->_nb >> this->_fracBits));
}

Fixed::Fixed()
{
	this->_nb = 0;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

std::ostream & operator<<(std::ostream & o, Fixed  const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
