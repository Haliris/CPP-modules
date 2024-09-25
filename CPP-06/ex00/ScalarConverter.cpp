
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

void	ScalarConverter::convert_char(char c)
{
	if (c <= 31 || c == 127)
		std::cout << "Non printable char input in convert_char()" << std::endl;
	else
	{	
		std::cout << "char: " << c << '\n';
		std::cout << "int: " << static_cast<int>(c) << '\n';
		std::cout << "float: " << static_cast<float>(c) << '\n';
		std::cout << "double: " << static_cast<double>(c) << '\n';
	}
}

bool	ScalarConverter::is_pseudo(std::string input)
{
	if (input == "+inff" || "-inff")
		return true;
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;
	return false;
}

bool	ScalarConverter::is_float(std::string input)
{
	int start = 0;
	int point = false;
	if (input[0] == '+' || input[0] == '-')
		start++;
	if (input[input.length() - 1] != 'f')
		return (false);
	for (int i = start; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
		{
			if (input[i] == 'f' && i == input.length() - 1)
				continue ;
			return false;
		}
		if (input[i] == '.')
		{
			if (point == true)
				return false;
			point = true;
		}
	}
	return (point);
}

bool	ScalarConverter::is_double(std::string input)
{
	int start = 0;
	int point = false;
	if (input[0] == '+' || input[0] == '-')
		start++;
	for (int i = start; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return false;
		if (input[i] == '.')
		{
			if (point == true)
				return false;
			point = true;
		}
	}
	return (point);
}

bool	ScalarConverter::is_int(std::string input)
{
	int start = 0;
	if (input[0] == '+' || input[0] == '-')
		start++;
	for (int i = start; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

void	ScalarConverter::convert_int(std::string input)
{
	int nb = atoi(input.c_str());
	std::cout << "char: " << nb << '\n';
	std::cout << "int: " << nb << '\n';
	std::cout << "float: " << static_cast<float>(nb) << '\n';
	std::cout << "double: " << static_cast<double>(nb) << '\n';
}


void	ScalarConverter::convert(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		convert_char(input[0]);
	else if (is_pseudo(input))
		convert_pseudo(input);
	else if (is_float(input))
		convert_float(input);
	else if (is_double(input))
		convert_double(input);
	else if (is_int(input))
		convert_int(input);
	else
		std::cout << "Unrecognized input in convert" << std::endl;
}
