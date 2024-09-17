/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:59:42 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 16:48:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Default Cat constructor called" << std::endl;
	brain = new(std::nothrow) Brain();
	if (brain == NULL)
		std::cout << "Failed to allocated Brain in Cat constructor!" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Default Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& copyCat) : Animal()
{
	std::cout << "Default Cat copy constructor called" << std::endl;
	*this = copyCat;
}

Cat	&Cat::operator=(const Cat& copyCat)
{
	std::cout << "Default Cat copy assignment operator called" << std::endl;
	if (this != &copyCat)
	{
		this->type = copyCat.type;
		this->brain = new(std::nothrow) Brain(*copyCat.brain);
		if (this->brain == NULL)
			std::cout << "Could not create new brain for Cat copy constructor, handle exit here" << std::endl;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

const std::string	Cat::getIdea(int idx)
{
	return brain->getIdea(idx);
}

void	Cat::addIdea(std::string newidea, int idx)
{
	brain->addIdea(newidea, idx);
}
