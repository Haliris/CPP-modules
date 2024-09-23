
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& copyScalarConverter)
{
    *this = copyScalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copyScalarConverter)
{
	(void)copyScalarConverter;
    return *this;
}

void	ScalarConverter::convert(std::string input)
{
	if (input.length() == 1 && isalpha(input[0]))
		convert_char(input[0]);
	else if (is_pseudo_litteral(input))
		convert_pseudo(input);
	else if (isfloat(input))
		convert_float(input);
	else if (isdouble(input))
		convert_double(input);
	else if (isint(input))
		convert_int(input);
}
