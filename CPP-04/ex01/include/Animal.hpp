/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:10:29 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 14:04:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <new>
# include <cstddef>

class	Animal
{
	private:
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& copyAnimal);
		Animal&	operator=(const Animal& copyAnimal);
		virtual ~Animal();
		virtual void				makeSound() const;
		virtual const std::string	getType() const;
};

#endif
