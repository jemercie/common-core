/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:08:50 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/16 14:40:40 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	int i;
	const Animal *tab[100];

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

	Animal *a = new Dog();
	Animal *b = new Dog();
	*a = *b;
	delete a;
	delete b;

	std::cout << std::endl << "*******TESTTEST********" << std::endl << std::endl;
	Dog g;
	g.setIdea("");
	for (int i = 0; i < 101; i++){
		g.setIdea("idée");
	}

	Dog tmp = g;
	std::cout << "idée   0: " << tmp.getIdea(0) << std::endl;
	std::cout << "idée   1: " << tmp.getIdea(1) << std::endl;
	std::cout << "idée   2: " << tmp.getIdea(2) << std::endl;
	std::cout << "idée  25: " << tmp.getIdea(25) << std::endl;
	std::cout << "idée  99: " << tmp.getIdea(99) << std::endl;
	std::cout << "idée 101: " << tmp.getIdea(101) << std::endl;

	Dog w;
	w = tmp;
	std::cout << "idée   0: " << w.getIdea(0) << std::endl;
	std::cout << "idée   1: " << w.getIdea(1) << std::endl;
	std::cout << "idée   2: " << w.getIdea(2) << std::endl;
	std::cout << "idée  25: " << w.getIdea(25) << std::endl;
	std::cout << "idée  99: " << w.getIdea(99) << std::endl;
	std::cout << "idée 101: " << tmp.getIdea(101) << std::endl;
	return (0);
}
