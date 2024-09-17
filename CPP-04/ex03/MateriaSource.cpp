/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:31:58 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 11:32:03 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource default destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copyMateriaSource)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = copyMateriaSource;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource& copyMateriaSource)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &copyMateriaSource)
	{
		for (int i = 0; i < copyMateriaSource.materia_nb; i++)
		{
			this->materias[i] = copyMateriaSource.materias[i]->clone();
			this->materia_nb++;
			if (this->materias[i] == NULL)
				std::cout << "Could not copy materias in MateriaSource copy" << std::endl;;
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (materia_nb > 3)
		std::cout << "MateriaSource full of materias, cannot learn more!" << std::endl;
	else
	{
		std::cout << "Learning new materia: " << m->getType() << std::endl;
		materias[materia_nb] = m;
		materia_nb++;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i=0; i < materia_nb; i++)
	{
		if (materias[materia_nb]->getType() == type)
			return materias[materia_nb]->clone();
	}
	std::cout << "Unknown materia type in createMateria()" << std::endl;
	return 0;
}
