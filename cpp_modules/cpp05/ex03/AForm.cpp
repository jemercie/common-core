/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:38:45 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/24 17:14:09 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void AForm::beSigned(Bureaucrat const &bureaucrat)
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

void AForm::executeForm(Bureaucrat const & executor)
{
	try
	{
		if (this->getSignedStatus() == 0)
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->getGradeRequiredToExec())
			throw AForm::GradeTooLowException();
		else
			this->execute(executor);
	}
	catch (std::exception &err){
		std::cout << err.what() << std::endl;
	}
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSignedStatus() const
{
	return (this->_signed);
}

int	AForm::getGradeRequiredToSign() const
{
	return (this->_grade2Sign);
}

int	AForm::getGradeRequiredToExec() const
{
	return (this->_grade2Exec);
}

AForm::AForm(const std::string name, const int grade2Sign, const int grade2Exec) : _name(name), _signed(0), _grade2Sign(grade2Sign), _grade2Exec(grade2Exec)
{
	if (grade2Sign < 1)
		throw GradeTooLowException();
	if (grade2Sign > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &rhs) : _name(rhs._name), _signed(0), _grade2Sign(rhs._grade2Sign), _grade2Exec(rhs._grade2Exec)
{
}

AForm &AForm::operator=(AForm const &rhs)
{
	(void) rhs;
	return (*this);
}

AForm::~AForm()
{
}

const char *AForm::GradeTooHighException::what() const  throw()
{
	return ("Error : grade too high\n");
}

const char *AForm::GradeTooLowException::what() const  throw()
{
	return ("Error : grade too low\n");
}

const char *AForm::AlreadySignedException::what() const  throw()
{
	return ("This Form is already signed!\n");
}

const char *AForm::FormNotSignedException::what() const  throw()
{
	return ("You can't execute the form, it's not signed!\n");
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << "AForm inAFormations : " << std::endl;
	o << "    name  : " << rhs.getName() << std::endl;
	o << "    signed: " << rhs.getSignedStatus() << std::endl;
	o << "    min grade to sign : " << rhs.getGradeRequiredToSign() << std::endl;
	o << "    min grade to exec : " << rhs.getGradeRequiredToExec() << std::endl;
	return (o);
}
