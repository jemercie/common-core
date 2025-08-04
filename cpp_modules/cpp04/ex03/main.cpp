/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:10:53 by jemercie          #+#    #+#             */
/*   Updated: 2023/10/02 17:34:13 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ICharacter.hpp"
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "MateriaSource.hpp"

int main(void)
{
	MateriaSource *src = new MateriaSource();
	IMateriaSource* rrr = new MateriaSource(*src);

	rrr->createMateria("ice");
	rrr->createMateria("dfgsd"); //			try to create a wrong materia
	rrr->learnMateria(new Ice());
	rrr->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp = NULL;

	Character aaaa("yaaaa");

	aaaa.equip(tmp);
	src->learnMateria(new Ice());
	tmp = src->createMateria("ice"); //		try to equip 2 times the same materia
	aaaa.equip(tmp);
	aaaa.equip(tmp);

	tmp = aaaa.getPtr4Unequip(0);
	aaaa.unequip(0);
	if (tmp != NULL)
		me->equip(tmp);
	tmp = rrr->createMateria("ice");
	me->equip(tmp);
	tmp = rrr->createMateria("cure");
	me->equip(tmp);
	tmp = rrr->createMateria("cure");
	me->equip(tmp);
	tmp = rrr->createMateria("cure"); //	try to equip a fifth materia
	me->equip(tmp);
	delete tmp;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete me;
	delete bob;
	delete src;
	delete rrr;
	return 0;
}
