/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:02:29 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/08 18:13:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string	input;
	Phonebook	phonebook;

	while(true)
	{
		std::cout << "Enter a command: " << std::flush;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nEOF" << std::endl;
			break;
		}
		if (input == EXIT)
			break ;
		else if (input == ADD)
			phonebook.add_contact() ;
		else if (input == SEARCH)
			phonebook.search_contact() ;
	}
	return (0);
}
