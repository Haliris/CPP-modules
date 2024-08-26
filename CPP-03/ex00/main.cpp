/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:49:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/26 12:53:00 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	trap01("01");
	ClapTrap	trap01Copy = trap01;

	std::string	grunt = "grunt";
	trap01.attack(grunt);
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01.takeDamage(5);
	trap01.beRepaired(5);
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01.takeDamage(1);
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01.takeDamage(5);
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
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
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01.takeDamage(3);
	trap01.beRepaired(1);
	trap01.attack(grunt);
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01.takeDamage(10);
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01.takeDamage(10);


	trap01.attack(grunt);
	trap01.beRepaired(1);
	trap01.takeDamage(5);

	std::cout << "Claptrap 01's copy turn!" << std::endl;
	trap01Copy.attack(grunt);

	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01Copy.takeDamage(9);
	trap01Copy.beRepaired(1);
	trap01Copy.attack(grunt);
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01Copy.takeDamage(9000);
	std::cout  << "Grunt attacks Claptrap 01!" << std::endl;
	trap01Copy.takeDamage(9000);
	trap01Copy.beRepaired(1);
	return (0);
}
