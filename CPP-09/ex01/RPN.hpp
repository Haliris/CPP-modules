
#pragma once
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <ctype.h>

class Equation
{
	private:
		Equation();
		Equation(const Equation& copy);
		Equation& operator=(const Equation& copy);
		std::stack<char>	_stack;
	public:
		Equation(const std::string& input);
		~Equation();
		bool	isOperator(const std::string& token);
		void	validateInput(const std::string& input);
		void	process() const;
};


