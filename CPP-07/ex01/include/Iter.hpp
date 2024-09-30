
#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T, typename F>
void	iter(T* array, size_t size, F f)
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void	myprint(const T c)
{
	std::cout << c;
}
#endif
