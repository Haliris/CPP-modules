/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:55:04 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/18 17:08:07 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	phone_number;
		std::string	secret;
	public:
		Contact();
		std::string	get_name();
		std::string	get_last_name();
		std::string	get_phone_number();
		std::string	get_secret();
		void		display();
};
