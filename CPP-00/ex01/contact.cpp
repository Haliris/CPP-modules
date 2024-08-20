/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:02:11 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/20 14:27:07 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {

}

std::string	Contact::get_first_name() const {
	return this->first_name;
}

std::string	Contact::get_last_name() const {
	return this->last_name;
}

std::string	Contact::get_nickname() const {
	return this->nickname;
}

std::string	Contact::get_phone_nb() const {
	return this->phone_nb;
}

std::string	Contact::get_secret() const {
	return this->darkest_secret;
}

static void	display_entry(std::string entry)
{
	if (entry.length() > 10)
		entry = entry.substr(0, 9) + ".";
	else
	{
		for (size_t i = 0; i < 10 - entry.length(); i++)
			std::cout << ' ';
	}
	std::cout << entry;
	std::cout << '|';
}

void	Contact::display() const
{
	display_entry(first_name);
	display_entry(last_name);
	display_entry(nickname);
	display_entry(phone_nb);
	display_entry(darkest_secret);
	std::cout << std::endl;
}

static bool	validate_phone_nb(std::string phone_nb)
{
	if (phone_nb.length() != 10)
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
	// char		c;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> *input;
	// while (std::cin.get(c))
	// {
	// 	if (std::cin.eof())
	// 	{
	// 		std::cout << "\nEOF" << std::endl;
	// 		break;
	// 	}
	// 	if (c == '\n')
	// 		break ;
	// 	*input += c;
	// }

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
		std::cout << "Invalid phone number. Enter a 10 digits phone number: ";
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
