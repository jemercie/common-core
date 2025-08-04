/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:42:54 by jemercie          #+#    #+#             */
/*   Updated: 2023/09/18 15:42:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *one = newZombie("one");
	one->announce();
	delete one;
	std::cout << "zombie one deleted" << std::endl;
	randomChump("ratata");
	return (0);
}
