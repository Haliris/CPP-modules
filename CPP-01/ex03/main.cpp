/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:37:52 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/10 13:24:35 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		club.setType("double club");
		club.setType("double club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		Weapon duo = Weapon("double spiked club");
		HumanB jim("Jim");
		jim.setWeapon(NULL);
		jim.attack();
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		jim.setWeapon(&duo);
		jim.setWeapon(&duo);
		jim.attack();
	}
	return 0;
}
