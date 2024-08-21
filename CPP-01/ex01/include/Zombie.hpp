/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:33:57 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/21 14:27:51 by jteissie         ###   ########.fr       */
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
		Zombie ();
		void	announce(void);
		void	setName(std::string name);
		~Zombie (void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
