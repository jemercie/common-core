/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:51:10 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/12 10:51:20 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr->value));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    static Data ret;

    ret.value = reinterpret_cast<unsigned int*>(raw);
    return (&ret);
}

