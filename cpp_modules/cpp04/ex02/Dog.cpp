/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:12:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:50:04 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound() const
{
	std::cout << "Dog sound **WOOF**." << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}

std::string	Dog::getIdea(int i) const
{
	return (this->brainnn->getIdea(i));
}

void	Dog::setIdea(std::string idea)
{
	this->brainnn->setIdea(idea);
}

Dog::Dog()
{
	std::cout << "Dog constructor called." << std::endl;
	this->type = "Dog";
	this->brainnn = new Brain();
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called." << std::endl;
	this->type = "Dog";
	this->brainnn = new Brain(*src.brainnn);

}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->type = rhs.type;
	if (this->brainnn)
		delete (this->brainnn);
	this->brainnn = new Brain(*rhs.brainnn);
	return (*this);
}

Dog::~Dog()
{
	delete this->brainnn;
	std::cout << "Dog destructor called." << std::endl;
}

