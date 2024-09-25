#include "ScalarConverter.hpp"

int main(void)
{
	std::string c = "s";
	std::string test = "42";
	std::string testf = "42.0f";
	std::string testd = "42.0";

	ScalarConverter::convert(c);
	ScalarConverter::convert(test);
	ScalarConverter::convert(testf);
	ScalarConverter::convert(testd);
	ScalarConverter::convert(c);
}
