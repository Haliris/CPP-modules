/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:00:00 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/09 14:01:10 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string level;
	Harl	Harl_2_0;

	if (ac != 2)
	{
		std::cout << "Give me a proper filtering level!" << std::endl;
		return (1);
	}
	level = av[1];
	Harl_2_0.filter(level);
	return (0);
}
