/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:26:05 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/23 12:09:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float Point::get_x_y(bool xy) const
{
	if (xy)
		return (this->_x);
	return (this->_y);
}

Point	& Point::operator=(Point const & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs.get_x_y(1);
		this->_y = rhs.get_x_y(0);
	}
	return *this;
}

Point::Point(float const x, float const y)
{
	this->_x = x;
	this->_y = y;
}

Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(Point const & src)
{
	*this = src;
}

Point::~Point()
{
}
