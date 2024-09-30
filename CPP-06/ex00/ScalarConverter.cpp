/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:57:02 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/30 14:57:06 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_char(std::string input)
{
	long long c = atoll(input.c_str());

	if (c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min())
		std::cout << "Char: impossible" << std::endl;
	else if (input.length() == 1 && !isdigit(input[0]))
		std::cout << "Char: " << static_cast<char>(input[0]) << std::endl;
	else if (!isprint(c))
		std::cout << "Char: non-printable" << '\n';
	else
		std::cout << "Char: " << static_cast<char>(c) << std::endl;
}

void	print_int(std::string input)
{
	int nb = atoi(input.c_str());

	if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
		std::cout << "Int: impossible" << std::endl;
	else if (input.length() == 1 && !isdigit(input[0]))
		std::cout << "Int: " << static_cast<int>(input[0]) << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(nb) << std::endl;
}

void	print_float(std::string input)
{
	double	nb = atof(input.c_str());

	if (input.length() == 1 && !isdigit(input[0]))
		std::cout << "Float: " << static_cast<float>(input[0]) << ".0";
	else if (std::isfinite(nb) && std::floor(nb) == nb)
		std::cout << "Float: " << static_cast<float>(nb) << ".0";
	else
		std::cout << "Float: " << static_cast<float>(nb);
	std::cout << "f" << std::endl;
}

void	print_double(std::string input)
{
	double	nb = atof(input.c_str());

	if (input.length() == 1 && !isdigit(input[0]))
		std::cout << "Double: " << static_cast<double>(input[0]) << ".0" << std::endl;
	else if (std::isfinite(nb) && std::floor(nb) == nb)
		std::cout << "Double: " << static_cast<double>(nb) << ".0" << std::endl;
	else if (input.length() == 1 && !isdigit(input[0]))
		std::cout << "Double: " << static_cast<double>(input[0]) << std::endl;
	else
		std::cout << "Double: " << static_cast<double>(nb) << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
	print_char(input);
	print_int(input);
	print_float(input);
	print_double(input);
}
