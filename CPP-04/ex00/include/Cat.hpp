/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:00:00 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/09 17:00:30 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class	Cat: public Animal
{
	private:
	public:
		Cat();
		~Cat();
		Cat(const Cat& copyCat);
		Cat& operator=(const Cat& copyCat);
		void				makeSound() const;
};
#endif

