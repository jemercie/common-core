/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:24:17 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:01 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


std::string const & AMateria::getType() const
{
	return (this->_type);
}

AMateria &AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->is_equiped = rhs.is_equiped;
	}
	return (*this);
}

bool	AMateria::isEquiped() const
{
	return (this->is_equiped);
}

void	AMateria::setIsEquipedFlag(bool flag)
{
	this->is_equiped = flag;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type), is_equiped(0)
{
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::AMateria() : _type("default"), is_equiped(0)
{
}

AMateria::~AMateria()
{
}
