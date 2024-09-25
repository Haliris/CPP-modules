
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <tgmath.h>
# include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copyScalarConverter);
		ScalarConverter& operator=(const ScalarConverter& copyScalarConverter);
		static void	convert_char(char c);
		static bool	is_pseudo(std::string input);
		static void	convert_pseudo(std::string pseudo);
		static bool	is_float(std::string input);
		static void	convert_float(std::string input);
		static bool	is_double(std::string input);
		static void	convert_double(std::string input);
		static bool	is_int(std::string input);
		static void	convert_int(std::string input);
	public:
		static void	convert(std::string input);
};

#endif

