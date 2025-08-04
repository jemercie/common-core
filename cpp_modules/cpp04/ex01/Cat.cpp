/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:12:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:40:38 by jemercie         ###   ########.fr       */
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

std::string	Cat::getIdea(int i) const
{
	return (this->brainnn->getIdea(i));
}

void	Cat::setIdea(std::string idea)
{
	this->brainnn->setIdea(idea);
}

Cat::Cat()
{
	std::cout << "Cat constructor called." << std::endl;
	this->type = "Cat";
	this->brainnn = new Brain();
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->type = "Cat";
	this->brainnn = new Brain(*src.brainnn);
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->type = rhs.type;
	if (this->brainnn)
		delete (this->brainnn);
	this->brainnn = new Brain(*rhs.brainnn);
	return (*this);
}

Cat::~Cat()
{
	delete this->brainnn;
	std::cout << "Cat destructor called." << std::endl;
}
