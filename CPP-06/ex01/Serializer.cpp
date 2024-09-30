/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:18:05 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/30 16:18:22 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer& copy)
{
    *this = copy;
}

Serializer& Serializer::operator=(const Serializer& copy)
{
    if (this != &copy)
    {
    }
    return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
