/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:47:44 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/24 17:14:10 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat *b4 = new Bureaucrat("bureaucrat 4", 1);
	std::cout << *b4 << std::endl;

	Intern someRandomIntern;
	AForm* form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	form->beSigned(*b4);
	form->execute(*b4);
	delete form;
	std::cout << std::endl;

	form = someRandomIntern.makeForm("shrubbery creation", "Bender");
	form->beSigned(*b4);
	form->execute(*b4);
	delete form;
	std::cout << std::endl;

	form = someRandomIntern.makeForm("presidential pardon", "Bender");
	form->beSigned(*b4);
	form->execute(*b4);
	delete form;
	return (0);
}
