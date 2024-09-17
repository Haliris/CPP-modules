/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:49:16 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 15:49:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <iostream>
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria*	inventory[4];
		std::string	name;
		int			materia_nb;
	public:
		Character(); 
		~Character(); 
		Character(const Character& copyCharacter);
		Character& operator=(const Character& copyCharacter);
		Character(std::string const & name);
		std::string	const &	GetName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
