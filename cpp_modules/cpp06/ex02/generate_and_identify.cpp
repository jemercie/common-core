/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_and_identify.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:02:04 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/16 15:02:50 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_and_identify.hpp"

Base * generate(void)
{
    std::srand(std::time(NULL));
    int random = std::rand();
    random %= 3;
    switch (random)
    {
        case 0 :
            std::cout << "A class generated" << std::endl;
            return (new A());
            break;
        case 1 :
            std::cout << "B class generated" << std::endl;
            return (new B());
            break;
        case 2 :
            std::cout << "C class generated" << std::endl;
            return (new C());
            break;
    }
    return (NULL);
}

void identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
    if (a)
        std::cout << "class identified: " << *a;
    B* b = dynamic_cast<B*>(p);
    if (b)
        std::cout << "class identified: " << *b;
    C* c = dynamic_cast<C*>(p);
    if (c)
        std::cout << "class identified: " << *c;
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "class identified: " << a;
    }
    catch(std::exception &err)
    {}
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "class identified: " << b;
    }
    catch(std::exception &err)
    {}
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "class identified: " << c;
    }
    catch(std::exception &err)
    {}
}
