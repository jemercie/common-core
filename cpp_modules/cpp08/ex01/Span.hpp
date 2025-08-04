/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:36:55 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/23 16:37:15 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <iostream>

class Span
{
    public:
        Span();
        Span(unsigned int N);
        ~Span();

        Span    &operator=(Span const  & rhs);

        std::vector<int>    getVec() const;
        unsigned int        getN() const;

        class   EntityFullException : public std::exception
        {
            const char* what() const throw();
        };

        class   NotEnoughNumbersException : public std::exception
        {
            const char* what() const throw();
        };

        void            addNumber(int nb);
        void            addNumber(const std::vector<int>::iterator start, const std::vector<int>::iterator end);
        long long int   shortestSpan();
        long long int   longestSpan();
        void            printVectorContent() const;

    private:
        std::vector<int>    _vec;
        unsigned int        _N;

};

#endif
