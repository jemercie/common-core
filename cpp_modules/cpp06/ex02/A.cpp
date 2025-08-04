/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:16 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/16 15:06:27 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

std::ostream& operator<<(std::ostream& o, const A& obj)
{
    static_cast<void>(obj);
    o << "A" << std::endl;
    return o;
}

A::A()
{
    std::cout << "A constructor called." << std::endl;
}
A::~A()
{
    std::cout << "A destructor called." << std::endl;
}