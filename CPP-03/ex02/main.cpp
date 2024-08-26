/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:49:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/26 14:52:33 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	trap01("ClapTrap");
	ScavTrap	ScavTrap("ScavTrap");
	FragTrap	FragTrap("FragTrap");

	std::string	grunt = "grunt";
	trap01.attack(grunt);
	std::cout  << "Grunt attacks Claptrap!" << std::endl;
	trap01.takeDamage(5);
	trap01.beRepaired(5);
	std::cout  << "Grunt attacks Claptrap!" << std::endl;
	trap01.takeDamage(1);
	std::cout  << "Grunt attacks Claptrap!" << std::endl;
	trap01.takeDamage(5);
	std::cout  << "Grunt attacks Claptrap!" << std::endl;
	trap01.takeDamage(3);
	trap01.beRepaired(1);
	trap01.beRepaired(1);
	trap01.beRepaired(1);
	trap01.beRepaired(1);
	trap01.beRepaired(1);
	trap01.beRepaired(1);
	trap01.beRepaired(1);
	trap01.beRepaired(1);
	trap01.attack(grunt);
	trap01.beRepaired(1);
	std::cout  << "Grunt attacks Claptrap!" << std::endl;
	trap01.takeDamage(3);
	trap01.beRepaired(1);
	trap01.attack(grunt);
	std::cout  << "Grunt attacks Claptrap!" << std::endl;
	trap01.takeDamage(10);
	std::cout  << "Grunt attacks Claptrap!" << std::endl;
	trap01.takeDamage(10);
	trap01.attack(grunt);
	trap01.beRepaired(1);
	trap01.takeDamage(5);

	std::cout << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "ScavTrap's turn!" << std::endl;
	ScavTrap.guardGate();
	ScavTrap.attack(grunt);
	std::cout << "Grunt attacks ScavTrap!" << std::endl;
	ScavTrap.takeDamage(10);
	ScavTrap.beRepaired(10);
	std::cout << "Grunt attacks ScavTrap!" << std::endl;
	ScavTrap.takeDamage(10);
	ScavTrap.attack(grunt);
	std::cout << "Grunt attacks ScavTrap!" << std::endl;
	ScavTrap.takeDamage(10);
	ScavTrap.beRepaired(10);
	ScavTrap.attack(grunt);
	std::cout << "ScavTrap goes berserk!" << std::endl;
	for (int i = 0; i < 45; i++)
		ScavTrap.attack(grunt);
	ScavTrap.attack(grunt);
	std::cout  << "Grunt straight up KILLS ScavTrap!" << std::endl;
	ScavTrap.takeDamage(100);

	std::cout << "Grunt attacks ScavTrap!" << std::endl;
	ScavTrap.takeDamage(1);
	ScavTrap.attack(grunt);

	std::cout << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "FragTrap's turn!" << std::endl;
	FragTrap.highFivesGuys();
	FragTrap.attack(grunt);
	std::cout << "Grunt attacks FragTrap!" << std::endl;
	FragTrap.takeDamage(10);
	FragTrap.beRepaired(10);
	std::cout << "Grunt attacks FragTrap!" << std::endl;
	FragTrap.takeDamage(10);
	FragTrap.attack(grunt);
	std::cout << "Grunt attacks FragTrap!" << std::endl;
	FragTrap.takeDamage(10);
	FragTrap.beRepaired(10);
	FragTrap.attack(grunt);
	std::cout << "FragTrap goes berserk!" << std::endl;
	for (int i = 0; i < 95; i++)
		FragTrap.attack(grunt);
	FragTrap.attack(grunt);
	std::cout  << "Grunt straight up KILLS FragTrap!" << std::endl;
	FragTrap.takeDamage(100);

	std::cout << "Grunt attacks FragTrap!" << std::endl;
	FragTrap.takeDamage(1);
	FragTrap.attack(grunt);

	return (0);
}
