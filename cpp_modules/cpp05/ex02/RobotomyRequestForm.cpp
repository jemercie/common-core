/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:43:27 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/25 11:43:42 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static int nb = 0;

    std::cout << executor.getName() << " execute " << this->getName() << std::endl;

    std::cout << " * Makes some drilling noises *" << std::endl;
    if (nb % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy on target " << this->_target << " failed." << std::endl;
    nb++;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void) rhs;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm("Robotomy request form", 72, 45), _target(rhs._target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request form", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}