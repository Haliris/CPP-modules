#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v(5);
	for (int i = 0; i < 42 * 5; i+= 42)
		v.push_back(i);
	std::vector<int>::const_iterator vec_found = easyfind(v, 84);
	std::vector<int>::const_iterator vec_found3 = easyfind(v, 42);
	std::vector<int>::const_iterator vec_found4 = easyfind(v, 43);
	std::cout << "value found:" <<  *vec_found << std::endl;
	std::cout << "value found:" <<  *vec_found3 << std::endl;
	if (vec_found4 == v.end())
		std::cerr << "Error: value 43 not found within container" << std::endl;
	return 0;
}
