/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:56:49 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/26 19:52:05 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DefaultClapTrap"), ScavTrap(), FragTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->name = "diamondTrapDefault";
	this->hitPoints = FragTrap::getHp();
	std::cout << "HP: " << this->hitPoints << std::endl;
	this->attackDamage = FragTrap::getAd();
	std::cout << "AD: " << this->attackDamage << std::endl;
	this->energyPoints = ScavTrap::getEp();
	std::cout << "EP: " << this->energyPoints << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
	this->name = name;
	this->hitPoints = FragTrap::getHp();
	std::cout << "HP: " << this->hitPoints << std::endl;
	this->attackDamage = FragTrap::getAd();
	std::cout << "AD: " << this->attackDamage << std::endl;
	this->energyPoints = ScavTrap::getEp();
	std::cout << "EP: " << this->energyPoints << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap " << name << " has been copy constructed!" << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	std::cout << "HP: " << this->hitPoints << std::endl;
	this->attackDamage = copy.attackDamage;
	std::cout << "AD: " << this->attackDamage << std::endl;
	this->energyPoints = copy.energyPoints;
	std::cout << "EP: " << this->energyPoints << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "This is my local name " << this->name << std::endl;
	std::cout << "This is my ClapTrap name " << ClapTrap::getName() << std::endl;
}
