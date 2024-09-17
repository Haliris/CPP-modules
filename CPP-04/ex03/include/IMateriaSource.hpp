/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:31:44 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 11:32:03 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_SOURCE
# define IMATERIA_SOURCE
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

class MateriaSource : IMateriaSource
{
	private:
		AMateria*	materias[4];
		int			materia_nb;
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& copyMateriaSource);
		MateriaSource&	operator=(const MateriaSource& copyMateriaSource);
		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};


#endif
