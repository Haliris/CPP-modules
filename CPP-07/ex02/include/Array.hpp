#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class Array
{
	private:
		T				*array;
		unsigned int	array_size;
	public:
		Array();
		~Array();
		Array(const Array& copy);
		Array &operator=(const Array& copy);
		Array(unsigned int n);
		T &operator[](unsigned int n);
		unsigned int	size() const;
};

#endif
