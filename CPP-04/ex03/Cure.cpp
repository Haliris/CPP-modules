/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:41:43 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 15:41:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

Cure::Cure()
{
	std::cout << "Default Cure Materia constructor called" << std::endl;
	type = "cure";
}

Cure::~Cure() 
{
	std::cout << "Default Cure Materia destructor called" << std::endl;
}

Cure::Cure(const Cure& copyCure) : AMateria("cure")
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copyCure;
}

Cure	&Cure::operator=(const Cure& copyCure)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &copyCure)
		this->type = copyCure.type;
	return *this;
}

AMateria*	Cure::clone() const
{
	std::cout << "Cure clone() called" << std::endl;
	return new(std::nothrow) Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals" << target.GetName() << "'s wounds *" << std::endl;
}
