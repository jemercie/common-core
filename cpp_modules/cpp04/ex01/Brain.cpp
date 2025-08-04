/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:28:11 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:48:51 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string	Brain::getIdea(int i) const
{
	if (i > 99)
		return ("There are not that many ideas in this brain, choose an index between 0 and 99.");
	if (this->ideas[i].empty())
		return ("There are no idea in this compartment of the brain.");
	else
		return (this->ideas[i]);
}

void	Brain::setIdea(std::string idea)
{
	if (this->index == 100)
	{
		std::cout << "The brain is full ehhh." << std::endl;
		return;
	}
	if (idea.empty())
	{
		std::cout << "You can't fill the brain with void, sorry." << std::endl;
		return;
	}
	this->ideas[this->index] = idea;
	this->index++;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	for(int i = 0; i < rhs.index; i++){
		this->setIdea(rhs.getIdea(i));
	}
	this->index = rhs.index;
	return (*this);
}

Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
	this->index = 0;
	for(int i = 0; i < 100; i++){
		this->ideas[i] = "\0";
	}
}

Brain::Brain(Brain const & src)
{
	this->index = 0;
	for(int i = 0; i < 100; i++){
		this->ideas[i] = "\0";
	}
	for(int i = 0; i < src.index; i++){
		this->setIdea(src.getIdea(i));
	};
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}
