/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:49:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/12 16:52:10 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{

	DiamondTrap	DiamondTrapTest("DiamondTrap_1");
	DiamondTrap	DiamondTrapTest2("DiamondTrap_2");
	DiamondTrap	dummy;
	DiamondTrap	copy = DiamondTrapTest;

	std::cout << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "DiamondTrap's turn!" << std::endl;
	DiamondTrapTest.whoAmI();
	DiamondTrapTest2.whoAmI();
	dummy.whoAmI();
	copy.whoAmI();
	return (0);
}
