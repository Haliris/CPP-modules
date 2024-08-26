/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:33:02 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/26 19:52:34 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "default_ScavTrap";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for " << name << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this!= &copy)
	{
		ClapTrap::operator=(copy);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destroying ScavTrap " << name << std::endl;
}



void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{

		std::cout << this->name << " is DEAD and cannot do anything!" << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << this->name << " is out of energy and cannot do anything!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << this->name << " deals " << this->attackDamage << " damage to " << target << "!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->name << " is in Gate keeper mode." << std::endl;
}
