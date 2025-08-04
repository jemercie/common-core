/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:04:21 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/25 17:25:02 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static int	get_form_type(std::string name);

AForm *Intern::makeForm(std::string name, std::string target)
{
	int i = get_form_type(name);

	switch (i)
	{
		case 0 :{
			return (new RobotomyRequestForm(target));
			break;
		}
		case 1 :{
			return (new ShrubberyCreationForm(target));
			break;
		}
		case 2 :{
			return (new PresidentialPardonForm(target));
			break;
		}
		case 3 :{
			std::cout << "You can only create 3 forms :" << std::endl;
			std::cout << "      - 'robotomy request' form" << std::endl;
			std::cout << "      - 'shrubbery creation' form" << std::endl;
			std::cout << "      - 'presidential pardon' form" << std::endl << std::endl;
		}
	}
	return (NULL);
}

static int	get_form_type(std::string name)
{
	int i;

	std::string nameTab[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	for (i = 0; i < 3; i++){
			if (name.compare(nameTab[i]) == 0)
				break;
	}
	if (i < 3)
		std::cout << "Intern creates " << name << std::endl;
	return (i);
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return (*this);
}

Intern::Intern()
{
}

Intern::Intern(Intern const &rhs)
{
	(void) rhs;
}

Intern::~Intern()
{
}
