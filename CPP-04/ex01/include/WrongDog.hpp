
#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include "WrongAnimal.hpp"

class	WrongDog: public WrongAnimal
{
	private:
	public:
		WrongDog();
		~WrongDog();
		WrongDog(const WrongDog& copyDog);
		WrongDog& operator=(const WrongDog& copyDog);
		void				makeSound() const;
};
#endif
