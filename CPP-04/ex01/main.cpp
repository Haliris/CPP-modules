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
	Animal*		horde[10];
	Dog*		copyDog;
	Cat*		copyCat;
	std::string	idea;

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			horde[i] = new(std::nothrow) Dog();
			if (horde[i] == NULL)
			{
				std::cout << "Could not allocate memory for horde dogs" << std::endl;
				while (i >= 0)
					delete horde[i--];
				return (1);
			}
		}
		else
		{
	  		horde[i] = new(std::nothrow) Cat();
			if (horde[i] == NULL)
			{
				std::cout << "Could not allocate memory for horde cats" << std::endl;
				while (i >= 0)
					delete horde[i--];
				return (1);
			}
		}
	}
	for (int i = 0; i < 10; i++)	
		horde[i]->makeSound();

	dynamic_cast<Dog*>(horde[0])->addIdea("I love tennis balls!", 0);
	dynamic_cast<Cat*>(horde[5])->addIdea("I love napping!", 0);

	copyDog = new(std::nothrow) Dog(*dynamic_cast<Dog*>(horde[0]));
	copyCat = new(std::nothrow) Cat(*dynamic_cast<Cat*>(horde[5]));
	
	if (copyDog == NULL || copyCat == NULL)
	{
		std::cout << "Could not allocate memory for copy animals" << std::endl;
		if (copyDog)
			delete copyDog;
		if (copyCat)
			delete copyCat;
		for (int j = 0; j < 10; j++)
			delete horde[j];
		return (1);
	}

	std::cout << "------------" << std::endl;
	std::cout << "horde ideas" << std::endl;
	idea = dynamic_cast<Dog*>(horde[0])->getIdea(0);
	std::cout << idea << std::endl;
	idea = dynamic_cast<Cat*>(horde[5])->getIdea(0);
	std::cout << idea << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "copies ideas" << std::endl;
	idea = copyDog->getIdea(0);
	std::cout << idea << std::endl;
	idea = copyCat->getIdea(0);
	std::cout << idea << std::endl;

	std::cout << "------------" << std::endl;
	std::cout << "addIdea() called on deep copies" << std::endl;
	copyDog->addIdea("I want food...", 0);
	copyCat->addIdea("Leave me alone.", 0);
	std::cout << "------------" << std::endl;
	std::cout << "horde ideas" << std::endl;
	idea = dynamic_cast<Dog*>(horde[0])->getIdea(0);
	std::cout << idea << std::endl;
	idea = dynamic_cast<Cat*>(horde[5])->getIdea(0);
	std::cout << idea << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "copies ideas" << std::endl;
	idea = copyDog->getIdea(0);
	std::cout << idea << std::endl;
	idea = copyCat->getIdea(0);
	std::cout << idea << std::endl;

	std::cout << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "Single copy test" << std::endl;
	std::cout << std::endl;

	Dog copy_test;
	copy_test.addIdea("Copy brain test", 0);
	idea = copy_test.getIdea(0);
	std::cout << "copy_test idea: "<< idea << std::endl;
	{
		Dog temp = copy_test;
		idea = temp.getIdea(0);
		std::cout << "temp idea: " << idea << std::endl;
	}
	idea = copy_test.getIdea(0);
	std::cout << "copy_test idea: " << idea << std::endl;

	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;

	for (int j = 0; j < 10; j++)
		delete horde[j];
	delete copyDog;
	delete copyCat;
	return (0);
}
