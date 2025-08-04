/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:54 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/16 15:07:10 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate_and_identify.hpp"

int main (void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
