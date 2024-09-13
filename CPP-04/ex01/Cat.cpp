/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:59:42 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/09 17:22:35 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	brain = new Brain();
	type = "Cat";
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Default Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& copyCat)
{
	std::cout << "Default Cat copy constructor called" << std::endl;
	*this = copyCat;
}

Cat	&Cat::operator=(const Cat& copyCat)
{
	std::cout << "Default Cat copy assignment operator called" << std::endl;
	this->type = copyCat.type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

