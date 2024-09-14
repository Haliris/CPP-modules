/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:00:00 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 17:26:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Aanimal.hpp"
# include "Brain.hpp"

class	Cat: public Aanimal
{
	private:
		Brain	*brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat& copyCat);
		Cat& operator=(const Cat& copyCat);
		void				makeSound() const;
		const std::string	getIdea(int idx);
		void				addIdea(std::string newidea, int idx);
};
#endif

