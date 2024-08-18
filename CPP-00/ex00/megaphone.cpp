/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:00:35 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/18 16:11:16 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int		index;
	int		ac_index;

	index = 0;
	ac_index = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (ac_index < ac)
	{
		while (av[ac_index][index])
		{
			std::cout << (char)toupper(av[ac_index][index]);
			index++;
		}
		index = 0;
		ac_index++;
		if (ac_index == ac)
			break ;
		std::cout << " ";
	}
	std::cout << "\n";
	return (0);
}
