/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:43:44 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/18 15:52:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int i;

	Zombie *horde = zombieHorde(-1, "ratata"); 
	for (i = 0; i < 0; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
