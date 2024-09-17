/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stash.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:08:37 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/17 15:11:37 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STASH_HPP
# include "AMateria.hpp"

class Stash
{
	private:
		AMateria*	stash[100];
		int			stash_index;
	public:
		Stash();
		Stash(const Stash &);
		Stash &operator=(const Stash &);
		~Stash();
		void	addStash(AMateria* m);
		int		getIndex();
		bool	inStash(AMateria* m);
};
#endif
