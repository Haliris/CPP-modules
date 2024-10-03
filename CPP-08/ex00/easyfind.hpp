#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

template<typename T>
T easyfind(const T& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return it;
}
