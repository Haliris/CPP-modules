/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:30:45 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 11:32:03 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	std::cout << "Default WrongDog constructor called" << std::endl;
	type = "WrongDog";
}

WrongDog::~WrongDog()
{
	std::cout << "Default WrongDog destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& copyDog) : WrongAnimal()
{
	std::cout << "Default WrongDog copy constructor called" << std::endl;
	*this = copyDog;
}

WrongDog	&WrongDog::operator=(const WrongDog& copyDog)
{
	std::cout << "Default WrongDog copy assignment operator called" << std::endl;
	this->type = copyDog.type;
	return *this;
}

void	WrongDog::makeSound() const
{
	std::cout << "Wrong Bark! Wrong Bark!" << std::endl;
}

