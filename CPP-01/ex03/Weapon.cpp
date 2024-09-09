/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:56:16 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/09 13:48:28 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name) : type(name) {}

Weapon::~Weapon(void)
{
}

const std::string&	Weapon::getType()
{
	return type;
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}
