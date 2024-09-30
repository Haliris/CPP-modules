/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:18:19 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/30 16:18:22 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>

typedef struct Data
{
	int value;
} Data;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif

