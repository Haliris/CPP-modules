
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
	for (size_t i = start; i < input.length(); i++)
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
	for (size_t i = start; i < input.length(); i++)
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
	for (size_t i = start; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

void	ScalarConverter::convert_char(char c)
{
	if (c <= 31 || c == 127)
		std::cout << "Non printable char input in convert_char()" << std::endl;
	else
	{	
		std::cout << "Char: " << c << '\n';
		std::cout << "Int: " << static_cast<int>(c) << '\n';
		std::cout << "Float: " << static_cast<int>(c) << ".0f" << '\n';
		std::cout << "Double: " << static_cast<int>(c) << ".0" << std::endl;
	}
}

void	ScalarConverter::convert_int(std::string input)
{
	int nb = atoi(input.c_str());
	std::cout << "Char: " << static_cast<char>(nb) << '\n';
	if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << nb << '\n';
	std::cout << "Float: " << static_cast<float>(nb) << ".0f" << '\n';
	std::cout << "Double: " << static_cast<double>(nb) << ".0" << '\n';
}

void	ScalarConverter::convert_float(std::string input)
{
	double	nb = atof(input.c_str());

	std::cout << "Char: " << static_cast<char>(nb) << std::endl;
	std::cout << "Int: " << static_cast<int>(nb) << std::endl;
	if (std::isfinite(nb) && std::floor(nb) == nb)
		std::cout << "Float: " << static_cast<float>(nb) << ".0";
	else
		std::cout << "Float: " << static_cast<float>(nb);
	std::cout << "f" << std::endl;
	if (std::isfinite(nb) && std::floor(nb) == nb)
		std::cout << "Double: " << nb << ".0" << std::endl;
	else
		std::cout << "Double: " << nb << std::endl;
}

void	ScalarConverter::convert_double(std::string input)
{
	double	nb = atof(input.c_str());

	std::cout << "Char: " << static_cast<char>(nb) << '\n';
	std::cout << "Int: " << static_cast<int>(nb) << '\n';
	if (std::isfinite(nb) && std::floor(nb) == nb)
		std::cout << "Float: " << static_cast<float>(nb) << ".0f";
	else
		std::cout << "Float: " << static_cast<float>(nb) << 'f' << '\n';
	if (std::isfinite(nb) && std::floor(nb) == nb)
		std::cout << "Double: " << nb << ".0" << std::endl;
	else
		std::cout << "Double: " << nb << std::endl;
}

void	ScalarConverter::convert_pseudo(std::string input)
{
	double	nb = atof(input.c_str());
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << static_cast<float>(nb) << std::endl;
	std::cout << "Double: " << nb << std::endl; 
}

void	ScalarConverter::convert(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		convert_char(input[0]);
	else if (is_float(input))
		convert_float(input);
	else if (is_double(input))
		convert_double(input);
	else if (is_int(input))
		convert_int(input);
	else if (is_pseudo(input))
		convert_pseudo(input);
	else
		std::cout << "Unrecognized input in convert" << std::endl;
}
