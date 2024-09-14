/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:15:17 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 17:02:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"

Aanimal::Aanimal()
{
	std::cout << "default Aanimal constructor called." << std::endl;
	type = "default";
}

Aanimal::~Aanimal()
{
	std::cout << "default Aanimal destructor called." << std::endl;
}

Aanimal::Aanimal(const Aanimal& Aanimalcpy)
{
	std::cout << "default Aanimal copy constructor called." << std::endl;
	*this = Aanimalcpy;
}

Aanimal	&Aanimal::operator=(const Aanimal& copyAanimal)
{
	std::cout << "default Aanimal assignment operator called." << std::endl;
	if (this != &copyAanimal)
		this->type = copyAanimal.type;
	return *this;
}

void	Aanimal::makeSound() const
{
	std::cout << std::endl;
}

const std::string	Aanimal::getType() const
{
	return type;
}
