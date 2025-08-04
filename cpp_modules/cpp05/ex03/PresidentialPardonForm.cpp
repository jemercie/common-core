/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:45:10 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/25 11:45:27 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    std::cout << executor.getName() << " execute " << this->getName() << std::endl;

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	(void) rhs;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm("Robotomy request form", 72, 45), _target(rhs._target)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon form", 145, 137), _target(target)
{
}


PresidentialPardonForm::~PresidentialPardonForm()
{

}