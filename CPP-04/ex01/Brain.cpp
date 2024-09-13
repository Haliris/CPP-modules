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
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copyBrain.ideas[i];
	return *this;
}
