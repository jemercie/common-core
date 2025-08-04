/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:08:50 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:53:52 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	int i;
	const AAnimal *tab[100];
//	const AAnimal *j = new Animal();

	for (i = 0; i < 100; i++)
	{
		if (i < 50)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
		std::cout << i << std::endl;
	}
	for (i = 0; i < 100; i++)
	{
		std::cout << i << std::endl;
		delete tab[i];
	}
	Dog g;
	Dog tmp = g;
	return (0);
}
