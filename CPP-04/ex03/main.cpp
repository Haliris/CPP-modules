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
	MateriaSource*	materia_stash;
	Ice*			ice_materia;
	Cure*			cure_materia;
	Character*		bob;
	Character*		dummy;

	materia_stash = new(std::nothrow) MateriaSource();
	ice_materia = new(std::nothrow) Ice();
	cure_materia = new(std::nothrow) Cure();
	bob = new(std::nothrow) Character("Bob");
	dummy = new(std::nothrow) Character("dummy");
	if (ice_materia == NULL || cure_materia == NULL || materia_stash == NULL)
		return (1);
	if (!bob || !dummy)
		return (1);
	bob->equip(ice_materia);
	bob->use(0, *dummy);
	bob->unequip(0);
	delete bob;
	delete dummy;
	delete ice_materia;
	delete cure_materia;
	delete materia_stash;
}
