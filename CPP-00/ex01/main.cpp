/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:02:29 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/18 17:12:32 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.cpp"

int	main(void)
{
	std::string	input;
	Phonebook	phonebook;

	while(std::cin.eof() == FALSE)
	{
		std::cout << "Enter a command: ";
		std::cin >> input;
		if (strcmp(input, EXIT) == 0)
			break ;
		else if (strcmp(input, ADD) == 0)
			phonebook.add_contact() ;
		else if (strcmp(input, SEARCH) == 0)
			phonebook.search_contact() ;
	}
	return (0);
}
//endl needed or not
