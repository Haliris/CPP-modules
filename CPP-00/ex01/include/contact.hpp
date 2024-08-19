/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:55:04 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/19 14:29:24 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_nb;
		std::string	darkest_secret;
	public:
		Contact();
		void		create_contact();
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_phone_number();
		std::string	get_secret();
		void		display();
};
