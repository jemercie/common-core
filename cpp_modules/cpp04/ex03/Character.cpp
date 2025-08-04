/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:47:45 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 16:44:48 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m) 
{
	if (!m)
	{
		std::cout << "you can't equip void eh" << std::endl;
		return;
	}
	if (m->isEquiped() == 1)
	{
		std::cout << "this materia is already equiped" << std::endl;
		return;
	}
    for (int i = 0; i < 4 ; i++)
    {   
        if (this->materia[i] == NULL)
		{
			m->setIsEquipedFlag(1);
	    	this->materia[i] = m;
			return;
		}
    }
	std::cout << "no more place, unequip a materia to equip a new one" << std::endl;
}

AMateria* Character::getPtr4Unequip(int idx)
{
	if (idx > 3)
	{
		std::cout << "wrong index, must be between 0 and 3" << std::endl;
		return (NULL);
	}
	if (this->materia[idx] != NULL)
		return (this->materia[idx]);
	std::cout << "no materia at this index" << std::endl;
	return (NULL);
}

void Character::unequip(int idx)
{
	if (idx > 3)
	{
		std::cout << "wrong index, must be between 0 and 3" << std::endl;
		return;
	}
	if (this->materia[idx] != NULL)
	{
		this->materia[idx]->setIsEquipedFlag(0);
		this->materia[idx] = NULL;
		return;
	}
	std::cout << "no materia at this index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && this->materia[idx] != NULL)
		this->materia[idx]->use(target);
}

Character::Character(ICharacter const & src)
{
	Character yy = (Character)src;
}

Character &Character::operator=(ICharacter const &src)
{	
	Character yy = (Character)src;
	this->_name = yy._name;
;	for(int i = 0; i < 4; i++){
		if (this->materia[i] != NULL)
			delete (this->materia[i]);
		if (this->materia[i] == NULL)
			this->materia[i] = yy.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
	return (*this);
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++){
		this->materia[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++){
		if (this->materia[i] != NULL)
		{
			delete(this->materia[i]);
			this->materia[i] = NULL;
		}
	}
}

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++){
		this->materia[i] = NULL;
	}
}
