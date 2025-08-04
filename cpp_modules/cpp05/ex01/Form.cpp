/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:38:45 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/24 17:14:09 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() == 0)
			bureaucrat.signForm(0, this->_name, "he has no grade.");
		else if (this->_signed == 1)
			throw AlreadySignedException();
		else if (this->_grade2Sign >= bureaucrat.getGrade())
		{
			this->_signed = 1;
			bureaucrat.signForm(1, this->_name, "");
		}
		else
		{
			bureaucrat.signForm(0, this->_name, "bureaucrat's grade is too low.");
			throw GradeTooLowException();
		}
	}
	catch (std::exception &err){
		std::cout << err.what();
	}
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSignedStatus() const
{
	return (this->_signed);
}

int	Form::getGradeRequiredToSign() const
{
	return (this->_grade2Sign);
}

int	Form::getGradeRequiredToExec() const
{
	return (this->_grade2Exec);
}

Form::Form(const std::string name, const int grade2Sign, const int grade2Exec) : _name(name), _signed(0), _grade2Sign(grade2Sign), _grade2Exec(grade2Exec)
{
	if (grade2Sign < 1)
		throw GradeTooLowException();
	if (grade2Sign > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &rhs) : _name(rhs._name), _signed(0), _grade2Sign(rhs._grade2Sign), _grade2Exec(rhs._grade2Exec)
{
}

Form &Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const  throw()
{
	return ("Error : grade too high\n");
}

const char *Form::GradeTooLowException::what() const  throw()
{
	return ("Error : grade too low\n");
}

const char *Form::AlreadySignedException::what() const  throw()
{
	return ("This form is already signed!\n");
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form informations : " << std::endl;
	o << "    name  : " << rhs.getName() << std::endl;
	o << "    signed: " << rhs.getSignedStatus() << std::endl;
	o << "    min grade to sign : " << rhs.getGradeRequiredToSign() << std::endl;
	o << "    min grade to exec : " << rhs.getGradeRequiredToExec() << std::endl;
	return (o);
}
