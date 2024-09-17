/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:02 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 16:48:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
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

Dog::Dog(const Dog& copyDog) : Animal()
{
	std::cout << "Default Dog copy constructor called" << std::endl;
	*this = copyDog;
}

Dog	&Dog::operator=(const Dog& copyDog)
{
	std::cout << "Default Dog copy assignment operator called" << std::endl;
	if (this != &copyDog)
	{
		this->type = copyDog.type;
		this->brain = new(std::nothrow) Brain(*copyDog.brain);
		if (this->brain == NULL)
			std::cout << "Could not create new brain for Dog assignment operator, handle exit here" << std::endl;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark! Bark!" << std::endl;
}

const std::string	Dog::getIdea(int idx)
{
	return brain->getIdea(idx);
}

void	Dog::addIdea(std::string newidea, int idx)
{
	brain->addIdea(newidea, idx);
}
