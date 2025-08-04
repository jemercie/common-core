/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:50:38 by jemercie          #+#    #+#             */
/*   Updated: 2023/12/02 15:55:13 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>

class RPN
{
	public:
		RPN(std::string input);
		~RPN();

		class WrongInputException : public std::exception
		{
			const char* what() const throw();
		};

	private:
		enum {
			PLUS = 10,
			MINUS,
			MULTIPLICATION,
			DIVISION,
			SPACE
		} e_operator;

		bool		_checkInput();
		int     	getNextExpression();
		void		_calcul();

		RPN &operator=(RPN const &rhs);
		RPN(RPN const &src);

		std::stack<double>		_storeNb;
		std::string			_input;
		double					_result;
		int					_i;
};



#endif
