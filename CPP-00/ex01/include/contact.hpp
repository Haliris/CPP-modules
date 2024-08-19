/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:55:04 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/19 18:11:35 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <limits>
# include <iostream>
// # include "phonebook.hpp"
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
		std::string	get_first_name()	const;
		std::string	get_last_name()		const;
		std::string	get_nickname()		const;
		std::string	get_phone_nb()		const;
		std::string	get_secret()		const;
		void		display()			const;
};

#endif
