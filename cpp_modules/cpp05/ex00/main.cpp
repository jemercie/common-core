/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:47:44 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/19 15:08:44 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat *aa = new Bureaucrat("aa", -1);
		delete aa;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat *bb = new Bureaucrat("bb", 1532);
		delete bb;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		try
	{
		Bureaucrat *cc = new Bureaucrat("cc", 145);
	
		std::cout << " -> Decrement too much bureaucrat * " << cc->getName() << " *" << std::endl;
		for (int i = 0; i < 6; i++){
			cc->DecrementGrade();
			std::cout << "      * " << cc->getName() << " * grade is - " << cc->getGrade() << " -" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "     ** overload operator << **" << std::endl;
		std::cout << *cc << std::endl << std::endl;

		delete cc;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat *dd = new Bureaucrat("dd", 5);
		std::cout << " -> Increment too much bureaucrat * " << dd->getName() << " *" << std::endl;
		for (int i = 0; i < 5; i++){
			dd->IncrementGrade();
			std::cout << "      * " << dd->getName() << " * grade is - " << dd->getGrade() << " -" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "     ** overload operator << **" << std::endl;
		std::cout << *dd << std::endl << std::endl;

		delete dd;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
