
#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP
# include <iostream>

template <typename T>
void	swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void	min(T& a, T& b)
{
	return (a * (a < b) + b * (b < a));
}
template <typename T>
void	max(T& a, T& b)
{
	return (a * (b < a) + b * (a < b));
}
#endif

