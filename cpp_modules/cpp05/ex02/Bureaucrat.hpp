/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:48:17 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/24 17:14:09 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include "AForm.hpp"
class AForm;

# define SET 1
# define INCR 2
# define DECR 3


class Bureaucrat
{
	public :
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &rhs);
		~Bureaucrat();

		void	IncrementGrade();
		void	DecrementGrade();
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		class FormExecutionError : public std::exception
		{
			const char* what() const throw();
		};

		int			getGrade() const;
		std::string	getName() const;

		void	signForm(bool bureaucrat_signed, std::string formName, std::string reason) const;
		void	executeForm(AForm const & form) const;


	private :
		const std::string	_name;
		int					_grade;
		Bureaucrat &operator=(Bureaucrat const &rhs);

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);


#endif
