/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:31:56 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 15:16:39 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Stash.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	Stash		garbage_stash;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	dynamic_cast <Character*>(me)->assign_stash(&garbage_stash);
	ICharacter* you = new Character("you");
	dynamic_cast <Character*>(you)->assign_stash(&garbage_stash);
	ICharacter* hoarder = new Character("hoarder");
	dynamic_cast <Character*>(hoarder)->assign_stash(&garbage_stash);
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(3, *bob);
	me->use(5, *bob);
	me->unequip(1);
	me->unequip(-2);
	me->unequip(4);
	me->equip(NULL);
	std::cout << "-------------" << std::endl;
	std::cout << "you test" << std::endl;
	you->equip(tmp);
	you->use(0, *bob);
	tmp = src->createMateria("ice");
	you->equip(tmp);
	you->use(1, *bob);
	ICharacter* student = you;
	dynamic_cast <Character*>(student)->assign_stash(&garbage_stash);
	you->unequip(0);

	std::cout << "-------------" << std::endl;
	std::cout << "Student test" << std::endl;
	student->use(1, *bob);
	student->unequip(1);
	you->use(1, *bob);
	student->use(0, *bob);
	student->use(1, *bob);
	std::cout << "-------------" << std::endl;

	std::cout << "hoarder test" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			tmp = src->createMateria("ice");
		else
			tmp = src->createMateria("cure");
		hoarder->equip(tmp);
	}
	hoarder->equip(tmp);
	hoarder->equip(tmp);
	hoarder->unequip(1);
	hoarder->equip(tmp);
	for (int i = 0; i < 4; i++)
		hoarder->use(i, *bob);
	std::cout << "-------------" << std::endl;
	src->learnMateria(NULL);

	delete you;
	delete hoarder;
	delete bob;
	delete me;
	delete src;
	return 0;
}
