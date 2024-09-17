/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:30:41 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 11:32:03 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	type = "Dog";
}

WrongCat::~WrongCat()
{
	std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copyCat) : WrongAnimal()
{
	std::cout << "Default WrongCat copy constructor called" << std::endl;
	*this = copyCat;
}

WrongCat	&WrongCat::operator=(const WrongCat& copyCat)
{
	std::cout << "Default WrongCat copy assignment operator called" << std::endl;
	this->type = copyCat.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}

