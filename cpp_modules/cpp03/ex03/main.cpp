/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:46:32 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/10 12:43:26 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap nb1("ratata");
	DiamondTrap nb2("le rat");
	DiamondTrap nb3;
	DiamondTrap nb4(nb2);

	nb3 = nb1;

	std::cout << std::endl;	
/*
	nb1.attack("");
	nb1.attack(nb2.getName());
	nb1.attack(nb2.getName());
	nb1.attack(nb2.getName());
	nb1.attack(nb2.getName());
	nb2.takeDamage(nb1.getStats(AD));
	nb1.attack(nb2.getName());
	nb2.takeDamage(nb1.getStats(AD));
	nb1.attack(nb2.getName());
	nb2.takeDamage(nb1.getStats(AD));
	nb1.attack(nb2.getName());
	nb2.takeDamage(nb1.getStats(AD));
	nb1.attack(nb2.getName());
	nb2.takeDamage(nb1.getStats(AD));
	nb3.setNewName("ratata2");
	nb1.attack(nb3.getName());
	nb3.takeDamage(nb1.getStats(AD));
	nb1.attack(nb3.getName());
	nb3.takeDamage(nb1.getStats(AD));
	nb3.beRepaired(10);
	nb1.attack(nb3.getName());
	nb3.takeDamage(nb1.getStats(AD));
	nb1.attack(nb3.getName());
	nb3.takeDamage(nb1.getStats(AD));
	nb3.beRepaired(10);
*/
	nb3.whoAmI();

	std::cout << std::endl;	
	return (0);
}
