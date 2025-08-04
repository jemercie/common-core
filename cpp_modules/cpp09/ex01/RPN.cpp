/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:50:07 by jemercie          #+#    #+#             */
/*   Updated: 2023/12/02 15:55:28 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool checkChar(char c);

void	RPN::_calcul()
{
    int len = this->_input.length();

    for(;this->_i < len; this->_i++)
    {
        int next = getNextExpression();
        if (next > 9 && this->_i == 0)
            break;
        if (next < 10)
            this->_storeNb.push(next);
        else if (next != SPACE)
        {
            double tmp1 = this->_storeNb.top();
            this->_storeNb.pop();
            if (this->_storeNb.empty())
                break;
            double tmp2 = this->_storeNb.top();
            this->_storeNb.pop();
            if (next == PLUS)
                    this->_storeNb.push(tmp2 + tmp1);
            else if (next == MINUS)
                    this->_storeNb.push(tmp2 - tmp1);
            else if (next == MULTIPLICATION)
                    this->_storeNb.push(tmp2 * tmp1);
            else if (next == DIVISION)
            {
                if (tmp1 == 0)
                {
                    std::cerr << "You cannot divide any number by 0." << std::endl;
                    return;
                }
                else
                    this->_storeNb.push(tmp2 / tmp1);
            }
        }
    }
    if (this->_i == len)
    {
        this->_result = this->_storeNb.top();
        this->_storeNb.pop();
        if (this->_storeNb.empty())
            std::cout << this->_result << std::endl;
        else
            std::cerr << "Wrong number/operator patters, can't calcul." << std::endl;
    }
    else
        std::cerr << "Wrong number/operator patters, can't calcul." << std::endl;
}

int     RPN::getNextExpression()
{
    const static std::string set = "0123456789+-*/ ";
    int ret = 0;

    for(;this->_input[this->_i] != set[ret]; ret++){
    }
    return(ret);
}

RPN::RPN(std::string input) : _input(input), _i(0)
{
    if (!this->_checkInput())
        throw WrongInputException();
    this->_calcul();
}

bool	RPN::_checkInput()
{
    if (this->_input.empty())
        return (false);
    int len = this->_input.length();

    for (int i = 0; i < len; i++){
        if (!checkChar(this->_input[i]))
            return (false);
    }
    return (true);
}

static bool checkChar(char c)
{
    std::string set = "0123456789+-*/ ";
    for(size_t i = 0; i < set.size() ; i++){
        if (c == set[i])
            return (true);
    }
    return (false);
}

const char *RPN::WrongInputException::what() const  throw()
{
	return ("Wrong input, it must contain only numbers between 0 and 9 and operators +-*/.\n");
}

RPN::~RPN()
{
}
