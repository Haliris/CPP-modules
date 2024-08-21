/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:55:42 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/21 14:36:28 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* horde;

	std::cout << "-----------------" << std::endl;
	std::cout << "Testing for 0 Charles" << std::endl;
	horde = zombieHorde(0, "Charles");
	if (horde != NULL)
		delete[] horde;

	std::cout << "-----------------" << std::endl;
	std::cout << "Testing for 1 Thomas" << std::endl;
	horde = zombieHorde(1, "Thomas");
	if (horde != NULL)
		delete[] horde;

	std::cout << "-----------------" << std::endl;
	std::cout << "Testing for 5 Bobs" << std::endl;
	horde = zombieHorde(5, "Bob");
	if (horde != NULL)
		delete[] horde;

	std::cout << "-----------------" << std::endl;
	std::cout << "Testing for 10 Yohan" << std::endl;
	horde = zombieHorde(10, "Yohan");
	if (horde != NULL)
		delete[] horde;
}
