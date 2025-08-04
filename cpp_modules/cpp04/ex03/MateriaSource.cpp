/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:48:11 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/02 16:38:20 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void	MateriaSource::learnMateria(AMateria* yy) 
{
    for(int i = 0; i < 4; i++){
        if (materia_learned[i] == NULL)
        {
            this->materia_learned[i] = yy;
            return;
        }
    }
    std::cout << "You can't learn a new materia." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
    if (type.compare("ice") != 0 && type.compare("cure") != 0)
    {
        std::cout << "Materia " << type << " doesn't exist, you can try to create *ice* or *cure*." << std::endl;
        return (NULL);
    }
    for (int i = 0; i < 4; i++){
        if (materia_learned[i] != NULL && (type.compare(materia_learned[i]->getType()) == 0))
            return (materia_learned[i]->clone());
    }
    std::cout << "You must learn a materia before creating it." << std::endl;
    return (NULL);
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    for (int i = 0; i < 4; i++){
        if (src.materia_learned[i] == NULL)
            this->materia_learned[i] = NULL;
        else 
           this->materia_learned[i] = src.materia_learned[i]->clone();
   }
   return (*this);
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
   *this = src;
}

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++){
        this->materia_learned[i] = NULL;
   }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++){
        if (this->materia_learned[i] != NULL)
		{
            delete (this->materia_learned[i]);
            this->materia_learned[i] = NULL;
        }
    }
}