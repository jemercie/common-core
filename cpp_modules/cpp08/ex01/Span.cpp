/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:36:38 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/23 16:36:49 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

long long int Span::shortestSpan()
{
    if (this->_vec.size() < 2)
        throw NotEnoughNumbersException();

    std::sort(this->_vec.begin(), this->_vec.end());
    long long int ret = this->_vec.back() - this->_vec.front();
    std::vector<int>::iterator it = this->_vec.begin();
    std::vector<int>::iterator ite = this->_vec.end();

    for (; it + 1 != ite; it++){
        if ((*(it + 1) - *it) < ret)
            ret = (*(it + 1) - *it);
    }
    return (ret);
}

long long int Span::longestSpan()
{
    if (this->_vec.size() < 2)
        throw NotEnoughNumbersException();
    std::sort(this->_vec.begin(), this->_vec.end());
    return (this->_vec.back() - this->_vec.front());
}

void    Span::addNumber(int nb)
{
    if (this->_N == 0)
        throw EntityFullException();
    this->_vec.push_back(nb);
    this->_N--;
}

void    Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    for (; start != end; start++)
    {
        this->addNumber(*start);
    }
}

std::vector<int>    Span::getVec() const
{
    return (this->_vec);
}

void    Span::printVectorContent() const
{
    std::vector<int>::const_iterator it = this->_vec.begin();
    std::vector<int>::const_iterator ite = this->_vec.end();

	for	(; it != ite; it++) {
		std::cout << *it << std::endl;
	}
}

unsigned int    Span::getN() const
{
    return (this->_N);
}

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::~Span()
{
}

Span    &Span::operator=(Span const  & rhs)
{
    this->_vec = rhs.getVec();
    this->_N = rhs.getN();
    return (*this);
}

const char *Span::EntityFullException::what() const throw()
{
    return ("The entity cannot contain any new number.\n");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return ("Not enough numbers to find a span. Maybe add some new numbers and try again.\n");
}
