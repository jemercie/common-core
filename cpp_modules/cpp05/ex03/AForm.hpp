/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:39:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/24 17:14:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <fstream>
# include <iostream>
# include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public :
		AForm(const std::string name, const int grade2Sign, const int grade2Exec);
		AForm(AForm const &rhs);
		virtual ~AForm();


		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		class AlreadySignedException : public std::exception
		{
			const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			const char *what() const throw();
		};

		virtual std::string getName() const;
		virtual bool		getSignedStatus() const;
		virtual int			getGradeRequiredToSign() const;
		virtual int			getGradeRequiredToExec() const;

		virtual	void		execute(Bureaucrat const & executor) const = 0;
		virtual void 		beSigned(Bureaucrat const &bureaucrat);
		void				executeForm(Bureaucrat const & executor);

	private :
		const std::string	_name;
		bool				_signed;
		const int			_grade2Sign;
		const int			_grade2Exec;
		AForm &operator=(AForm const &rhs);

};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
