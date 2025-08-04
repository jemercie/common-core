/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:07:44 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/08 10:09:52 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <regex.h>
# include <cstdlib>
# include <limits.h>
# include <cstring>
# include <cctype>

class ScalarConverter
{
	public:

		static void	convert(char *str);

		class UnknownTypeException : public std::exception
		{
			const char* what() const throw();
		};


	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &rhs);

};


#endif
