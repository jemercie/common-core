/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:43:35 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/20 15:01:10 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template< typename T>

T const &	max(T const & x, T const & y)
{
	return ((x>y) ? x : y);
}
template< typename T>

T const &	min(T const & x, T const & y)
{
	return ((x>y) ? y : x);
}
template< typename T>

void	swap(T & y, T & x)
{
	T tmp = x;

	x = y;
	y = tmp;
}

#endif
