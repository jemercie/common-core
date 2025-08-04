/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:07:05 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/08 10:34:22 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int	check_type(char *str);
static void convertToChar(int type, void *nb, long int nb2check);
static void convertToInt(int type, void *nb, long int nb2check);
static void convertToFloat(int type, void *nb);
static void convertToDouble(int type, void *nb);
static void *getTheRightType(int type, char *str);

void	ScalarConverter::convert(char *str)
{
	int type = check_type(str);
	if (type == 10)
		throw UnknownTypeException();
	void *nb = getTheRightType(type, str);
	convertToChar(type, nb, strtol(str, NULL, 0));
	convertToInt(type, nb, strtol(str, NULL, 0));
	convertToFloat(type, nb);
	convertToDouble(type, nb);
}

static void convertToChar(int type, void *nb, long int nb2check)
{
	std::cout << "char: ";
	if (type > 3 || (nb2check != LONG_MIN && nb2check != LONG_MAX && (nb2check < 32 || nb2check > 126)))
		std::cout << "impossible";
	else if (type != 0 && !std::isprint(nb2check + '0'))
		std::cout << "non printable";
	else
	{
		if (type == 0)
			std::cout << *static_cast<char*>(nb);
		else if (type == 1)
			std::cout << static_cast<char>(*static_cast<int*>(nb));
		else if (type == 2)
			std::cout << static_cast<char>(*static_cast<float*>(nb));
		else if (type == 3)
			std::cout << static_cast<char>(*static_cast<double*>(nb));
	}
	std::cout << std::endl;
}

static void convertToInt(int type, void *nb, long int nb2check)
{
	if (type > 3 || nb2check < INT_MIN || nb2check > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: ";
	if (type == 0)
		std::cout << static_cast<int>(*static_cast<char*>(nb));
	else if (type == 1)
		std::cout << *static_cast<int*>(nb);
	else if (type == 2)
		std::cout << static_cast<int>(*static_cast<float*>(nb));
	else if (type == 3)
		std::cout << static_cast<int>(*static_cast<double*>(nb));
	std::cout << std::endl;
}

static void convertToFloat(int type, void *nbConv)
{
	std::cout << "float: ";
	float nb = 0;
	if (type == 0)
		nb = static_cast<float>(*static_cast<char*>(nbConv));
	else if (type == 1)
		nb = static_cast<float>(*static_cast<int*>(nbConv));
	else if (type == 2 || type > 6)
		nb = *static_cast<float*>(nbConv);
	else if (type > 2 && type < 7)
		nb = static_cast<float>(*static_cast<double*>(nbConv));
	std::cout << nb;
	if (nb - static_cast<int>(nb) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void convertToDouble(int type, void *nbConv)
{
	std::cout << "double: ";
	double nb = 0;
	if (type == 0)
		nb = static_cast<double>(*static_cast<char*>(nbConv));
	else if (type == 1)
		nb = static_cast<double>(*static_cast<int*>(nbConv));
	else if (type == 2 || type > 6)
		nb = static_cast<double>(*static_cast<float*>(nbConv));
	else if (type > 2 && type < 7)
		nb = *static_cast<double*>(nbConv);
	std::cout << nb;
	if (nb - static_cast<int>(nb) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

static void *getTheRightType(int type, char *str)
{
	if (type == 0)
		return (static_cast<void*>(&str[0]));
	else if (type == 1)
	{
		static long int nb = strtol(str, NULL, 0);
		return (static_cast<void*>(&nb));
	}
	else if (type == 2 || type > 6)
	{
		static float nb = strtof(str, NULL);
		return (static_cast<void*>(&nb));
	}
	else if (type > 2 && type < 7)
	{
		static double nb = strtod(str, NULL);
		return (static_cast<void*>(&nb));
	}
	return (NULL);
}

static int	check_type(char *str)
{
	regex_t	regex;
	const char *reg[9] = {"^[+-]?[0-9]{1,10}$", "^[+-]?[0-9]+[.]{1}[0-9]+[f]{1}$", "^[+-]?[0-9]+[.]{1}[0-9]+$","^nan$","^[+]inf$", "^[-]inf$", "^nanf$", "^[+]inff$", "^[-]inff$"};

	for (int i = 0; i < 9; i++)
	{
		if (regcomp(&regex, reg[i], REG_EXTENDED) < 0)
			return (-1);
		int res = regexec(&regex, str, (size_t) 0, NULL, 0);
		regfree(&regex);
		if (res == 0)
			return (i + 1);
	}
	if (std::strlen(str) == 1 && str[0] < 127 && str[0] > 31)
		return (0);
	return (10);
}

const char *ScalarConverter::UnknownTypeException::what() const  throw()
{
	return("Unknown type, can't convert.\n");
}
