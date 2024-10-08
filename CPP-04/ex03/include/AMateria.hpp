/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:59:49 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 14:59:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <iostream>
# include <new>
# include <cstddef>

class ICharacter;

class AMateria
{
	private:
	protected:
		std::string	type;
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria& copyAMateria);
		AMateria& operator=(const AMateria& copyAMateria);
		AMateria(std::string const & type);
		std::string const &	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

class Ice : public AMateria
{
	private:
	public:
		Ice();
		~Ice();
		Ice(const Ice& copyIce);
		Ice& operator=(const Ice& copyIce);
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

class Cure : public AMateria
{
	private:
	public:
		Cure();
		~Cure();
		Cure(const Cure& copyCure);
		Cure& operator=(const Cure& copyCure);
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
