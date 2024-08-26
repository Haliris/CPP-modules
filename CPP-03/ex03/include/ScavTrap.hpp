/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:29:22 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/26 15:17:31 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& copy);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};

#endif
