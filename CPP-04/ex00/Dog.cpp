/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:02 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 15:10:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Default Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& copyDog) : Animal()
{
	std::cout << "Default Dog copy constructor called" << std::endl;
	*this = copyDog;
}

Dog	&Dog::operator=(const Dog& copyDog)
{
	std::cout << "Default Dog copy assignment operator called" << std::endl;
	this->type = copyDog.type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark! Bark!" << std::endl;
}

