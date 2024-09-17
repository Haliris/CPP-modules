/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stash.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:07:54 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 15:11:24 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stash.hpp"

Stash::Stash()
{
	std::cout << "Stash default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->stash[i] = NULL;
	stash_index = 0;
}

Stash::Stash(const Stash& copyStash)
{
	std::cout << "Copy stash constructor called" << std::endl;
	*this = copyStash;
}

Stash	&Stash::operator=(const Stash& copyStash)
{
	std::cout << "Stash assignment operator called" << std::endl;
	if (this != &copyStash)
	{
		for (int i = 0; i < copyStash.stash_index; i++)
			this->stash[i] = copyStash.stash[i];
		this->stash_index = copyStash.stash_index;
	}
	return *this;
}

Stash::~Stash()
{
	std::cout << "Stash default destructor called" << std::endl;
	for (int i = 0; i < stash_index; i++)
		delete stash[i];
}

void	Stash::addStash(AMateria* m)
{
	if (stash_index == 100)
	{
		std::cout << "Stash full!" << std::endl;
		return ;
	}
	for (int i = 0; i < stash_index; i++)
	{
		if (this->stash[i] == m)
			return ;
	}
	std::cout << "Adding materia: " << m->getType() << " to stash" << std::endl;
	this->stash[stash_index] = m;
	stash_index++;
}

int	Stash::getIndex()
{
	return stash_index;
}

bool	Stash::inStash(AMateria* m)
{
	for (int i = 0; i < stash_index; i++)
	{
		if (this->stash[i] == m)
			return true;
	}
	return false;
}
