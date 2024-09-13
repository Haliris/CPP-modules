/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:02 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/09 17:12:14 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	brain = new Brain();
	type = "Dog";
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Default Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& copyDog)
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

