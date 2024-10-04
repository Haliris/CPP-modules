#include "Array.hpp"

int	main(void)
{
	try {
		Array<int> empty;
		Array<int> int_array(5);
		Array<char> char_array(10);

		std::cout << "empty array size: " << empty.size() << std::endl;
		std::cout << "int_array size: " << int_array.size() << std::endl;
		std::cout << "char_array size: " << char_array.size() << std::endl;
		std::cout << "Filling int_array" << std::endl;
		for (unsigned int i = 0; i < int_array.size(); i++)
			int_array[i] = i;
		std::cout << "Filling char_array" << std::endl;
		for (unsigned int i = 0; i < char_array.size(); i++)
			char_array[i] = 'A' + i;
		std::cout << "Printing arrays" << std::endl;
		std::cout << "int_array: ";
		for (unsigned int i = 0; i < int_array.size(); i++)
			std::cout << int_array[i];
		std::cout << std::endl;
		std::cout << "char_array: ";
		for (unsigned int i = 0; i < char_array.size(); i++)
			std::cout << char_array[i];
		std::cout << std::endl;


		Array<char> copy_char(char_array);
		std::cout << "copy_char: ";
		for (unsigned int i = 0; i < copy_char.size(); i++)
			std::cout << copy_char[i];
		std::cout << std::endl;
		std::cout << "Tolower called on copy_array" << std::endl;
		for (unsigned int i = 0; i < copy_char.size(); i++)
			copy_char[i] = tolower(copy_char[i]);
		std::cout << "copy_char: ";
		for (unsigned int i = 0; i < copy_char.size(); i++)
			std::cout << copy_char[i];
		std::cout << std::endl;
		std::cout << "char_array: ";
		for (unsigned int i = 0; i < char_array.size(); i++)
			std::cout << char_array[i];
		std::cout << std::endl;
		std::cout << "Empty array copy test" << std::endl;
		empty = int_array;
		std::cout << "Empty array size now:" << empty.size() << std::endl;
		for (size_t i = 0; i < empty.size(); i++)
			std::cout << " " << empty[i];
		std::cout << std::endl;
		std::cout << "CRASHING THIS TEST, WITH NO SURVIVORS" << std::endl;
		char_array[100] = 'F';
	}
	catch (std::exception & e)
	{
		std::cout << "[ARRAY][ERROR]: " << e.what();
	}
}
