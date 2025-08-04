/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:39:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/24 17:14:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	public :
		Form(const std::string name, const int grade2Sign, const int grade2Exec);
		Form(Form const &rhs);
		~Form();

		Form &operator=(Form const &rhs);

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

		std::string getName() const;
		bool		getSignedStatus() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredToExec() const;

		void 		beSigned(Bureaucrat const &bureaucrat);

	private :
		const std::string	_name;
		bool				_signed;
		const int			_grade2Sign;
		const int			_grade2Exec;

};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
