/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:17:52 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/18 17:41:47 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>
#include <string>

#define EXIT "EXIT"
#define ADD "ADD"
#define SEARCH "SEARCH"

#define MAX_CONTACTS 8

#define FALSE 0
#define TRUE 1

class PhoneBook {

	private:
		uint32_t	contact_nb;
		Contact		contacts[8];
	public:
		Phonebook();
		uint32_t	get_contact_nb();
		set			increment_contact_nb();
		void		add_contact();
		void		search_contact();
};

//Exit to add in main
