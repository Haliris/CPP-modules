/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:02:11 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/19 15:08:02 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

static bool	validate_phone_nb(std::string phone_nb)
{
	if (phone_nb.length != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (phone_nb[i] < '0' || phone_nb[i] > '9')
			return false;
	}
	return true;
}

static void	read_input(std::string *input)
{
	char		c;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (std::cin.get(c))
	{
		if (std::cin.eof())
		{
			std::cout << "\nEOF" << std::endl;
			break;
		}
		if (c == '\n')
			break ;
		*input += c;
	}

}

void	Contact::create_contact()
{
	std::string	first_name, last_name, nickname, phone_nb, darkest_secret;

	std::cout << "First name: ";
	read_input(&first_name);
	std::cout << "Last name: ";
	read_input(&last_name);
	std::cout << "Nickname: ";
	read_input(&nickname);
	std::cout << "Phone number: ";
	read_input(&phone_nb);
	while (validate_phone_nb(phone_nb) == false)
	{
		std::cout << "Invalid phone number. Enter a 10 digits phone number: \n"
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		read_input(&phone_nb);
	}
	std::cout << "Darkest secret: ";
	read_input(&darkest_secret);
	// std::getline(std::cin >> std::ws, darkest_secret);

	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_nb = phone_nb;
	this->darkest_secret = darkest_secret;
}
