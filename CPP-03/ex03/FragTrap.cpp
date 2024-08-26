/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:45:31 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/26 19:49:00 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default Constructor called" << std::endl;
	this->name = "default_FragTrap";
	this->hitPoints = 100;
	this->energyPoints = 100;
	std::cout << "EP: " << this->energyPoints << std::endl;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap default constructor called for " << name << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	std::cout << "EP: " << this->energyPoints << std::endl;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap	&FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this!= &copy)
	{
		ClapTrap::operator=(copy);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destroying FragTrap " << name << std::endl;
}

void	FragTrap::attack(const std::string& target)
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->name << "wants to high five the other Claptraps! (idk what the subject meant here)" << std::endl;
}