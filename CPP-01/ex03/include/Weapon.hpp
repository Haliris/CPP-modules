/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:50:26 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/21 15:05:16 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class	Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string name);
		const std::string&	getType();
		void				setType(std::string new_type);
		~Weapon(void);
};

#endif
