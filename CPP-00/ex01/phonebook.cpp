/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:01:54 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/19 14:12:04 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : contact_nb(0) {}

uint32_t Phonebook::get_contact_nb() const
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
	uint32_t contact_nb = get_contact_nb();
	Contact new_contact;

	create_contact(&new_contact);
	if (contact_nb == 8)
	{
		for (int i; i = 0; i < 7)
			this->contact[i + 1] = this->contact[i];
		contact[0] = new_contact;
	}
	else
	{
		this->contact[contact_nb + 1] = new_contact();
		increment_contact_nb();
	}
}

void Phonebook::search_contact()
{
	uint32_t index;

	this->display_contact();
	std::cout << "Enter contact index: ";
	std::cin >> index;

	if (index < 1 || index > this->contact_nb)
		std::cout << "Invalid index!" << std::endl;
	else
		contacts[index - 1].display();
}
