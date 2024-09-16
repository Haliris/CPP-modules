/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:14:24 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 16:14:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	materia_nb = 0;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& copyCharacter)
{
	std::cout << "Character copy constructor called" << std::endl;
}

Character	&Character::operator=(const Character& copyCharacter)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &copyCharacter)
	{
		*this = copyCharacter;
		for (int i = 0; i < copyCharacter.materia_nb; i++)
		{
			if (this->inventory[i] != NULL)
			{
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
			this->inventory[i] = copyCharacter.inventory[i]->clone();
			if (this->inventory[i] == NULL)
			   std::cout << "Could not allocate memory to copy new materia!" << std::endl;
			this->name = copyCharacter.name;
		}
	}
	return *this;
}

Character::Character(std::string const & name)
{
	std::cout << "Character name constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	materia_nb = 0;
}

std::string const &	Character::GetName()
{
	return this->name;
}

void	Character::equip(AMateria* m)
{
	if (materia_nb < 4 && inventory[materia_nb] == NULL)
	{
		inventory[materia_nb] = new(std::nothrow) AMateria(m);
		if (inventory[materia_nb] == NULL)
		{
			std::cout << "Could not equip new materia!" << std::endl;
			return ;
		}
		materia_nb++;
	}
	else
		std::cout << name << "'s inventory is full!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		std::cout << "Unequip index out of array bounds!" << std::endl;
	else if (inventory[idx] == NULL)
		std::cout << "No materia to unequip at this index!" << std::endl;
	else
	{
		std::cout << "Unequipped Materia at idx: " << idx << std::endl;
		inventory[idx] = NULL;
		materia_nb--;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0)
		std::cout << "Unequip index out of array bounds!" << std::endl;
	else if (inventory[idx] == NULL)
		std::cout << "No materia to use at this index!" << std::endl;
	else
		this->inventory[idx]->AMateria::use(target);
}
