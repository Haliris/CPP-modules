#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& copyBrain)
{
	std::cout << "Default Brain copy constructor called" << std::endl;
	*this = copyBrain;
}

Brain	&Brain::operator=(const Brain& copyBrain)
{
	std::cout << "Default Brain copy assignment operator called" << std::endl;
	this->type = copyBrain.type;
	return *this;
}
