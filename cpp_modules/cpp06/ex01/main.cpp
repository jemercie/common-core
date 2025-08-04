/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:50:05 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/12 10:51:04 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data ptr;

    *ptr.value = 123456;
    uintptr_t kk = Serializer::serialize(&ptr);
    Data *yyy = Serializer::deserialize(kk);

    std::cout << "initial  data ptr value:     " << *ptr.value << std::endl;
    std::cout << "after serialize ptr value:   " << kk << std::endl;
    std::cout << "after deserialize ptr value: " << *yyy->value << std::endl;
    return (0);
}