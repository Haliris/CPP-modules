#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	type = "Dog";
}

WrongCat::~WrongCat()
{
	std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copyCat)
{
	std::cout << "Default WrongCat copy constructor called" << std::endl;
	*this = copyCat;
}

WrongCat	&WrongCat::operator=(const WrongCat& copyCat)
{
	std::cout << "Default WrongCat copy assignment operator called" << std::endl;
	this->type = copyCat.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}

