/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:02:29 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/19 17:49:38 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string	input;
	Phonebook	phonebook;

	while(std::cin.eof() == false)
	{
		std::cout << "Enter a command: ";
		std::cin >> input;
		if (input == EXIT)
			break ;
		else if (input == ADD)
			phonebook.add_contact() ;
		else if (input == SEARCH)
			phonebook.search_contact() ;
	}
	return (0);
}
//endl needed or not
