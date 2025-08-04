/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:30 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/16 15:06:37 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

std::ostream& operator<<(std::ostream& o, const B& obj)
{
    static_cast<void>(obj);
    o << "B" << std::endl;
    return o;
}

B::B()
{
    std::cout << "B constructor called." << std::endl;
}
B::~B()
{
    std::cout << "B destructor called." << std::endl;
}