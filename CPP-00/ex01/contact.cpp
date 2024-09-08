/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:02:11 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/08 19:03:29 by marvin           ###   ########.fr       */
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
	std::cout << std::endl;
}

static bool	validate_phone_nb(std::string phone_nb)
{
	if (phone_nb == "NULL")
		return true;
	if (phone_nb.length() != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (phone_nb[i] < '0' || phone_nb[i] > '9')
			return false;
	}
	return true;
}

static std::string	read_input(void)
{
	std::string	input;

	std::cin.clear();
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cout << "read_input error: EOF sent, exiting" << std::endl;
		input = "NULL";
	}
	return (input);
}

void	Contact::create_contact()
{
	std::string	first_name, last_name, nickname, phone_nb, darkest_secret;

	std::cout << "First name: ";
	first_name = read_input();
	std::cout << "Last name: ";
	last_name = read_input();
	std::cout << "Nickname: ";
	nickname = read_input();
	std::cout << "Phone number: ";
	phone_nb = read_input();
	while (validate_phone_nb(phone_nb) == false)
	{
		std::cin.clear();
		std::cout << "Invalid phone number. Enter a 10 digits phone number: ";
		phone_nb = read_input();
	}
	std::cout << "Darkest secret: ";
	darkest_secret = read_input();
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_nb = phone_nb;
	this->darkest_secret = darkest_secret;
}
