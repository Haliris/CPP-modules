/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:33:57 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/21 14:13:25 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie (std::string name);
		~Zombie (void);
		void	announce(void);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif
