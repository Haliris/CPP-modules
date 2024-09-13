#include "WrongDog.hpp"

WrongDog::WrongDog()
{
	std::cout << "Default WrongDog constructor called" << std::endl;
	type = "Cat";
}

WrongDog::~WrongDog()
{
	std::cout << "Default WrongDog destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& copyDog)
{
	std::cout << "Default WrongDog copy constructor called" << std::endl;
	*this = copyDog;
}

WrongDog	&WrongDog::operator=(const WrongDog& copyDog)
{
	std::cout << "Default WrongDog copy assignment operator called" << std::endl;
	this->type = copyDog.type;
	return *this;
}

void	WrongDog::makeSound() const
{
	std::cout << "Wrong Bark! Wrong Bark!" << std::endl;
}

