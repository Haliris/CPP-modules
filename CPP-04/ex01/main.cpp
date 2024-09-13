/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:02:43 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/09 17:23:02 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* bad_meta = new WrongAnimal();
	const WrongAnimal* bad_j = new WrongDog();
	const WrongAnimal* bad_i = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << bad_j->getType() << " " << std::endl;
	std::cout << bad_i->getType() << " " << std::endl;
	bad_i->makeSound(); //will output the wrong cat sound!
	bad_j->makeSound();
	bad_meta->makeSound();
	
	delete i;
	delete j;
	delete meta;

	delete bad_i;
	delete bad_j;
	delete bad_meta;
	return (0);
}
