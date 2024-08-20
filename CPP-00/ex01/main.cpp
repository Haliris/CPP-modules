/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:02:29 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/20 15:23:42 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string	input;
	Phonebook	phonebook;

	while(true)
	{
		std::cout << "Enter a command: ";
		if (!(std::cin >> input))
			break ;
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
