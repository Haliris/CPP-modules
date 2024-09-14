/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:52:16 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 17:26:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Aanimal.hpp"
# include "Brain.hpp"

class	Dog: public Aanimal
{
	private:
		Brain	*brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& copyDog);
		Dog& operator=(const Dog& copyDog);
		void				makeSound() const;
		const std::string	getIdea(int idx);
		void				addIdea(std::string newidea, int idx);
};
#endif
