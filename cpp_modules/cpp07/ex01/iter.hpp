/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:07:01 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/20 15:11:35 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T, typename U>
void iter(T &array, size_t len, void (*f)(U))
{
    for (size_t i = 0; i < len; i++){
        f(array[i]);
    }
}
void    clearInt(int &array)
{
    array = 0;
}
void    clearStr(std::string &array)
{
    array = "0";
}

#endif
