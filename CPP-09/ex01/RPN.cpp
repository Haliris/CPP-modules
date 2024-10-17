
#include "RPN.hpp"
#include <cstdint>

Equation::Equation()
{
}

Equation::~Equation()
{
}

Equation::Equation(const Equation& copy)
{
    *this = copy;
}

Equation& Equation::operator=(const Equation& copy)
{
    if (this != &copy)
    {
    }
    return *this;
}

bool	Equation::isOperator(const char token)
{
	if (token == '-' || token == '+' || token == '*' || token == '/')
		return true;
	return false;
}

Equation::Equation(const std::string& input) : _input(input)
{
	std::string			token;
	std::stringstream	streamInput(input);
	while (getline(streamInput, token, ' '))
	{
		if (token.size() != 1 || (!isOperator(token[0]) && !(std::isdigit(token[0]))))
			throw std::runtime_error("Error: unexpected character in input");
	}
}

void	Equation::process()
{
	int					result = 0;
	char				op;
	std::string			token;
	std::stringstream	stream(_input);

	while (getline(stream, token, ' '))
	{
		if (std::isdigit(token[0]))
			_stack.push(token[0] - '0');
		if (isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw (std::runtime_error("Error: cannot perform operation on one or less numbers"));
			op = token[0];
			result = _stack.top();
			_stack.pop();
			if (op == '+')
				result += _stack.top();
			else if (op == '-')
				result -= _stack.top();
			else if (op == '*')
				result *= _stack.top();
			else if (op == '/')
				result /= _stack.top();
			_stack.pop();
			_stack.push(result);
		}
	}
}
