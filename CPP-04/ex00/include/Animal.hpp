/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:10:29 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/09 14:24:47 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class	Animal
{
	private:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& copyAnimal);
		Animal&	operator=(const Animal& copyAnimal);
		~Animal();
		virtual void	makeSound();
};

#endif
