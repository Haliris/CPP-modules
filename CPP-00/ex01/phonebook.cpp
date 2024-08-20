/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:01:54 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/20 14:24:36 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : contact_nb(0) {}

int Phonebook::get_contact_nb() const
{
	return this->contact_nb;
}

void Phonebook::increment_contact_nb()
{
	if (this->contact_nb < MAX_CONTACTS)
		this->contact_nb = this->contact_nb + 1;
}

void Phonebook::add_contact()
{
	int contact_nb = get_contact_nb();
	Contact new_contact;

	new_contact.create_contact();
	if (contact_nb == MAX_CONTACTS)
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			this->contacts[i + 1] = this->contacts[i];
		contacts[0] = new_contact;
	}
	else
	{
		this->contacts[contact_nb] = new_contact; // check this hardcoded shit
		increment_contact_nb();
	}
}

void Phonebook::display_header() const
{
	for (int i = 0; i < contact_nb; i++)
		this->contacts[i].display();
}

void Phonebook::list_info(Contact contact)
{
	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << "Last name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone number: " << contact.get_phone_nb() << std::endl;
	std::cout << "Darkest secret: " << contact.get_secret() << std::endl;
}

void Phonebook::search_contact()
{
	int index;

	this->display_header();
	std::cout << "Enter contact index: ";
	std::cin >> index;

	if (index < 1 || index > this->contact_nb)
	{
		std::cout << "Invalid index!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	else
		this->list_info(contacts[index - 1]);
}
