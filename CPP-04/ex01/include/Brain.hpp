#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain& copyBrain);
		Brain&	operator=(const Brain& copyBrain);
		const std::string	getIdea(int idx);
		void				addIdea(std::string newidea, int idx);
};

#endif
