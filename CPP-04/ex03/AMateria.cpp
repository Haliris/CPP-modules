/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:12:10 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 15:12:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	type = "default_materia";
}

AMateria::~AMateria()
{
	std::cout << "AMateria default destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copyAMateria)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = copyAMateria;
}

AMateria	&AMateria::operator=(const AMateria& copyAMateria)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &copyAMateria)
		this->type = copyAMateria.type;
	return *this;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria type string constructor called" << std::endl;
	this->type = type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "default AMAteria use() called targetting: " << target.name << std::endl;
}
