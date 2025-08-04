/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:46:32 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/27 17:29:54 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap *test;
	ClapTrap nb1("ratata");
	ClapTrap nb2("le rat");
	ClapTrap nb3;
	ClapTrap nb4(nb2);

	nb3 = nb1;

	std::cout << std::endl;	

	test = NULL;
	nb1.attack("");
	nb1.attack(nb2.getName());
	nb1.attack(nb2.getName());
	nb1.attack(nb2.getName());
	nb1.setAD(3);
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
	nb3.beRepaired(2);
	nb1.attack(nb3.getName());
	nb3.takeDamage(nb1.getStats(AD));
	nb1.attack(nb3.getName());
	nb3.takeDamage(nb1.getStats(AD));
	nb3.beRepaired(2);


	std::cout << std::endl;	
	return (0);
}
