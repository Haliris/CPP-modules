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
# include <iostream>
# include <new>
# include <cstddef>

class AMateria
{
	private:
	protected:
		std::string	type;
	public:
		AMateria();
		~AMateria();
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
		Ice*	clone();
		void	use(ICharacter& target);
};

Class Cure : public AMateria
{
	private:
	public:
		Cure();
		~Cure();
		Cure(const Cure& copyCure);
		Cure& operator=(const Cure& copyCure);
		Cure*	clone();
		void	use(ICharacter& target);
};


#endif