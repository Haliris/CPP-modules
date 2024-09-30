#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data		*ptr;
	Data		*deserialized;
	uintptr_t	raw;
	ptr = new Data;	
	ptr->value = 42;
	raw = Serializer::serialize(ptr);
	std::cout << "raw: " << raw << std::endl;
	deserialized = Serializer::deserialize(raw);
	std::cout << "ptr value: " << ptr->value << std::endl;
	std::cout << "deserialized value: " << deserialized->value << std::endl;
	delete ptr;
}
