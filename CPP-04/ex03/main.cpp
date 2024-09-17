/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:31:56 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 11:32:03 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");
	ICharacter* hoarder = new Character("hoarder");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
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
	you->unequip(0);

	std::cout << "-------------" << std::endl;
	std::cout << "Student test" << std::endl;
	student->use(1, *bob);
	student->unequip(1);
	you->use(1, *bob);
	student->use(0, *bob);
	student->use(1, *bob);
	std::cout << "-------------" << std::endl;


	std::cout << "-------------" << std::endl;
	std::cout << "hoarder test" << std::endl;
	for (int i = 0; i < 4; i++)
		hoarder->equip(tmp);
	hoarder->equip(tmp);
	hoarder->equip(tmp);
	hoarder->unequip(1);
	hoarder->equip(tmp);
	for (int i = 0; i < 4; i++)
		hoarder->use(i, *bob);
	std::cout << "-------------" << std::endl;
	src->learnMateria(NULL);

	delete you;
//	delete hoarder;
	delete bob;
	delete me;
	delete src;
	return 0;
}
