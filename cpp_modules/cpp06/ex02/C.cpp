/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:48 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/16 15:06:49 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

std::ostream& operator<<(std::ostream& o, const C& obj)
{
    static_cast<void>(obj);
    o << "C" << std::endl;
    return o;
}

C::C()
{
    std::cout << "C constructor called." << std::endl;
}
C::~C()
{
    std::cout << "C destructor called." << std::endl;
}