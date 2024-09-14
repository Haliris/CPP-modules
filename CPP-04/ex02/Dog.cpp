/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:02 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 17:26:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Aanimal()
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

Dog::Dog(const Dog& copyDog) : Aanimal()
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
		this->brain = new Brain(*copyDog.brain);
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
