#include "easyfind.hpp"

int main(void)
{
	std::string s = "Hello World";
	int int_array[5] = {0, 1, 42, 2, 5};
	std::vector<int> v(5);
	for (int i = 0; i < 42 * 5; i+= 42)
		v.push_back(i);

	std::cout << "String test: " << easyfind(s, 72) << std::endl;
	std::cout << "int array test " << easyfind(int_array, 42) << std::endl;
	std::cout << "vector test " << easyfind(v, 84) << std::endl;
}
