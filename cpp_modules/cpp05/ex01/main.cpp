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

#include "Form.hpp"

int main(void)
{
	Bureaucrat *b1 = new Bureaucrat("bureaucrat 1", -1); // -> GradeTooLowException error
	std::cout << *b1 << std::endl;
	Bureaucrat *b2 = new Bureaucrat("bureaucrat 2", 1532); // -> GradeTooHighException error
	std::cout << *b2 << std::endl;
	Bureaucrat *b3 = new Bureaucrat("bureaucrat 3", 125);
	std::cout << *b3 << std::endl;
	Bureaucrat *b4 = new Bureaucrat("bureaucrat 4", 5);
	std::cout << *b4 << std::endl;

	Form	*form1 = new Form("form 1", 6, 8);
	std::cout << *form1 << std::endl;  // -> display form1 informations
	Form form2(*form1);
	std::cout << form2 << std::endl;  // -> display form2 informations (copy constructor)
	Form	form3("form 3", 125, 100);
	std::cout << form3 << std::endl;  // -> display form3 informations
	form1->beSigned(*b3);	// -> try to sign but throw GradeTooLowException
	form2.beSigned(*b1);	// -> try to sign but have no grade throw NoGradeException
	form1->beSigned(*b4);
	form1->beSigned(*b3);	// -> already signed form throw AlreadySignedException

	delete b1;
	delete b2;
	delete b3;
	delete b4;

	delete form1;
	return (0);
}
