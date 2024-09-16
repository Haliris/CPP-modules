/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:21:22 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 15:21:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

Ice::Ice()
{
	std::cout << "Default Ice Materia constructor called" << std::endl;
	type = "ice";
}

Ice::~Ice() 
{
	std::cout << "Default Ice Materia destructor called" << std::endl;
}

Ice::Ice(const Ice& copyIce) : AMateria("ice")
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copyIce;
}

Ice	&Ice::operator=(const Ice& copyIce)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &copyIce)
		this->type = copyIce.type;
	return *this;
}

AMateria*	Ice::clone() const
{
	std::cout << "Ice clone() called" << std::endl;
	return new(std::nothrow) Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.GetName() << " *" << std::endl;
}
