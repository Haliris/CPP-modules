/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:02:43 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/14 15:55:07by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	Animal*	horde[10];
	Dog*		copyDog;
	Cat*		copyCat;
	std::string	idea;

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			horde[i] = new Dog();
		else
	  		horde[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)	
		horde[i]->makeSound();

	copyDog = new Dog(*dynamic_cast<Dog*>(horde[0]));
	copyCat = new Cat(*dynamic_cast<Cat*>(horde[5]));
	
	dynamic_cast<Dog*>(horde[0])->addIdea("I love tennis balls!", 0);
	dynamic_cast<Cat*>(horde[5])->addIdea("I love napping!", 0);
	copyDog->addIdea("I want food...", 0);
	copyCat->addIdea("Leave me alone.", 0);

	idea = dynamic_cast<Dog*>(horde[0])->getIdea(0);
	std::cout << idea << std::endl;
	idea = dynamic_cast<Cat*>(horde[5])->getIdea(0);
	std::cout << idea << std::endl;
	idea = copyDog->getIdea(0);
	std::cout << idea << std::endl;
	idea = copyCat->getIdea(0);
	std::cout << idea << std::endl;
	for (int j = 0; j < 10; j++)
		delete horde[j];
	delete copyDog;
	delete copyCat;
	return (0);
}
