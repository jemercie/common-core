/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:51:13 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/23 18:13:47 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void Bureaucrat::signForm(bool bureaucrat_signed, std::string formName, std::string reason) const
{
	if (bureaucrat_signed == 1)
		std::cout << this->_name << " signed " << formName << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << formName << " because " << reason << std::endl;
}

void Bureaucrat::IncrementGrade()
{
	try{
		if (this->_grade == 1)
			throw GradeTooHighException();
		else 
			this->_grade -= 1;
	}
	catch(std::exception &err){
		std::cout << err.what();
	}
}

void Bureaucrat::DecrementGrade()
{
	try{
		if (this->_grade == 150)
			throw GradeTooLowException();
		else 
			this->_grade += 1;
	}
	catch(std::exception &err){
		std::cout << err.what();
	}
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	try{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch(std::exception &err)
	{
		std::cout << err.what();
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("You cannot set or increment this bureaucrat's * grade higher than 1.\n");
}

const char *Bureaucrat::GradeTooLowException::what() const  throw()
{
	return ("You cannot set or decrement this bureaucrat's * grade lower than 150.\n");
}

const char *Bureaucrat::FormExecutionError::what() const  throw()
{
	return ("A problem occured executing the form.\n");
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	(void) rhs;
	return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
{
	*this = rhs;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream & operator<<(std::ostream & o, Bureaucrat  const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}
