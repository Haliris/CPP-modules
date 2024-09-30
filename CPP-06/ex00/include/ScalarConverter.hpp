
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
	public:
		static void	convert(std::string input);
};

#endif

