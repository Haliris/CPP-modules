/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:10:29 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 17:25:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Aanimal_HPP
# define Aanimal_HPP
# include <iostream>
# include <new>
# include <cstddef>

class	Aanimal
{
	private:
	protected:
		std::string	type;
	public:
		Aanimal();
		Aanimal(const Aanimal& copyAanimal);
		Aanimal&	operator=(const Aanimal& copyAanimal);
		virtual ~Aanimal();
		virtual void				makeSound() const = 0;
		virtual const std::string	getType() const;
};

#endif
