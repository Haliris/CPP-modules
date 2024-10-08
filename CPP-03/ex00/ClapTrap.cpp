/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:38:38 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/12 16:40:18 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Claptrap default constructor called for " << name << std::endl;
	name = "default";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Claptrap name constructor called for " << name << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Claptrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "Claptrap assignment operator called" << std::endl;
	if (this!= &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destroying ClapTrap " << name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{

		std::cout << "ClapTrap " << name << " is DEAD and cannot do anything!" << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy and cannot do anything!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " deals " << attackDamage << " damage to " << target << "!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "Stop hitting Claptrap " << name << " he is already dead!" << std::endl;
		return ;
	}
	std::cout << "Claptrap " << name << " takes " << amount << " damage!" << std::endl;
	if (amount >= hitPoints)
	{
		std::cout << "Claptrap " << name << " is dead! :(" << std::endl;
		hitPoints = 0;
	}
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
