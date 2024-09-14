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

const std::string	Brain::getIdea(int idx)
{
	if (idx > 99)
	{
		std::cout << "Index out of bound of ideas array!" << std::endl;
		return "buffer overflow ideas";
	}
	else	
		return ideas[idx];
}

void	Brain::addIdea(std::string newidea, int idx)
{
	if (idx > 99)
		std::cout << "Index out of bound of ideas array!" << std::endl;
	else
		ideas[idx] = newidea;
}