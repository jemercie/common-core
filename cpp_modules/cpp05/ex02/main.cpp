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

int main(void)
{
	Bureaucrat *b3 = new Bureaucrat("bureaucrat 3", 125);
	std::cout << *b3 << std::endl;
	Bureaucrat *b4 = new Bureaucrat("bureaucrat 4", 5);
	std::cout << *b4 << std::endl;

	AForm	*form11 = new ShrubberyCreationForm("target111");
	std::cout << *form11 << std::endl;  // -> display AForm1 inAFormations
	RobotomyRequestForm form22("target 222");
	std::cout << form22 << std::endl;  // -> display AForm2 inAFormations (copy constructor)
	PresidentialPardonForm form33("target 333");
	std::cout << form33 << std::endl;  // -> display AForm3 inAFormations
	form11->beSigned(*b4);
	form22.beSigned(*b4);
	form33.beSigned(*b4);

	form11->execute(*b4);
	form22.execute(*b4);
	form33.execute(*b4);

	delete b3;
	delete b4;

	delete form11;
	return (0);
}
