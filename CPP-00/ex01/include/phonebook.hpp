/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:17:52 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/20 13:45:23 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"
# include <iostream>
# include <string>

# define EXIT "EXIT"
# define ADD "ADD"
# define SEARCH "SEARCH"

# define MAX_CONTACTS 8
class Phonebook
{
	private:
		int			contact_nb;
		Contact		contacts[MAX_CONTACTS];

	public:
		Phonebook();
		int			get_contact_nb()	const;
		void		increment_contact_nb();
		void		add_contact();
		void		search_contact();
		void		display_header()	const;
		void		list_info(Contact contact);
};
#endif
