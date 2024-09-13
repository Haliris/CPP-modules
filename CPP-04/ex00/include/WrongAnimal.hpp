
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class	WrongAnimal
{
	private:
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copyAnimal);
		WrongAnimal&	operator=(const WrongAnimal& copyAnimal);
		virtual ~WrongAnimal();
		virtual void				makeSound() const;
		virtual const std::string	getType() const;
};

#endif
