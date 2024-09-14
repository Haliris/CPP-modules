/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:02:43 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 14:01:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	const Animal* horde[20];

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
			horde[i] = new Dog();
		else
	  		horde[i] = new Cat();
	}
	
	for (int j = 0; j < 20; j++)
	{
		delete horde[j];
	}
	return (0);
}
