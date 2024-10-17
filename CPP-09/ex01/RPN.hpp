
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
		const std::string	_input;
		std::stack<int>	_stack;
	public:
		Equation(const std::string& input);
		~Equation();
		bool	isOperator(const char token);
		void	process();
};


