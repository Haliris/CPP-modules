#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "default WrongAnimal constructor called." << std::endl;
	type = "default";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "default WrongAnimal destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& Animalcpy)
{
	std::cout << "default WrongAnimal copy constructor called." << std::endl;
	*this = Animalcpy;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& copyAnimal)
{
	std::cout << "default WrongAnimal assignment operator called." << std::endl;
	this->type = copyAnimal.type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "default wrong animal sound" << std::endl;
}

const std::string	WrongAnimal::getType() const
{
	return type;
}
