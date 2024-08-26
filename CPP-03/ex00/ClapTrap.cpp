/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:38:38 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/26 11:52:20 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Creating Claptrap " << name << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destroying ClapTrap " << name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy and cannot do anything!" << std::endl;
		return ;
	}
	if (hitPoints == 0)
	{

		std::cout << "ClapTrap " << name << " is DEAD and cannot do anything!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " deals " << attackDamage << " damage to " << target << "!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "Stop hitting Claptrap, he is already dead! :(" << std::endl;
		return ;
	}
	std::cout << "Claptrap " << name << " takes " << amount << " damage!" << std::endl;
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy and cannot do anything!" << std::endl;
		return ;
	}
	if (hitPoints == 0)
	{

		std::cout << "ClapTrap " << name << " is DEAD and cannot do anything!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "Claptrap " << name << " repairs himself for " << amount << " points." << std::endl;
	hitPoints += amount;
}
