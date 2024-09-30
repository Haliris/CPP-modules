#include "Array.hpp"

int	main(void)
{
	Array<int> int_array(5);
	Array<char> char_array(10);

	std::cout << "int_array size: " << int_array.size() << std::endl;

}
