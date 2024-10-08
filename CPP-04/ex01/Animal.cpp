/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:15:17 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 17:02:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "default Animal constructor called." << std::endl;
	type = "default";
}

Animal::~Animal()
{
	std::cout << "default Animal destructor called." << std::endl;
}

Animal::Animal(const Animal& Animalcpy)
{
	std::cout << "default Animal copy constructor called." << std::endl;
	*this = Animalcpy;
}

Animal	&Animal::operator=(const Animal& copyAnimal)
{
	std::cout << "default Animal assignment operator called." << std::endl;
	if (this != &copyAnimal)
		this->type = copyAnimal.type;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << std::endl;
}

const std::string	Animal::getType() const
{
	return type;
}
