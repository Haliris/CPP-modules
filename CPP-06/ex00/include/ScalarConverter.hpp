
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copyScalarConverter);
		ScalarConverter& operator=(const ScalarConverter& copyScalarConverter);
		void	convert_char(char c);
		bool	is_pseudo(std::string input);
		void	convert_pseudo(std::string pseudo);
		bool	is_float(std::string input);
		void	convert_float(std::string input);
		bool	is_double(std::string input);
		void	convert_double(std::string input);
		bool	is_int(std::string input);
		void	convert_int(std::string input);
	public:
		static void	convert(std::string input);
};

#endif

