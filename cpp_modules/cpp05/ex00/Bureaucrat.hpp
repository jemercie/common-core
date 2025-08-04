/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:48:17 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/22 16:20:56 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
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
		int			getGrade() const;
		std::string	getName() const;

		Bureaucrat &operator=(Bureaucrat const &rhs);

	private :
		const std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);


#endif
