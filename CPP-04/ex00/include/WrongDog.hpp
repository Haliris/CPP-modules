/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:30:56 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 11:32:03 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include "WrongAnimal.hpp"

class	WrongDog: public WrongAnimal
{
	private:
	public:
		WrongDog();
		~WrongDog();
		WrongDog(const WrongDog& copyDog);
		WrongDog& operator=(const WrongDog& copyDog);
		void				makeSound() const;
};
#endif
