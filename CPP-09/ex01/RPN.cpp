
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

bool	Equation::isOperator(const std::string& token)
{

	if (token.size() != 1)
		return false;
	if (token[0] == '-' || token[0] == '+' || token[0] == '*' || token[0] == '/')
		return true;
	return false;
}

void	Equation::validateInput(const std::string& input)
{
	std::string			token;
	std::stringstream	streamInput(input);
	while (getline(streamInput, token, ' '))
	{
		if (!isOperator(token) && !(std::isdigit(token[0])))
			throw std::runtime_error("Error: unexpected character in input");
		_stack.push(token[0]);
	}
}

Equation::Equation(const std::string& input)
{
	try
	{
		validateInput(input);
	}
	catch (std::exception &e)
	{

		std::cerr << e.what() << std::endl;
	}
	
}

void	Equation::process() const
{
	int	result = 0;

	while (_stack.size() != 1)
	{
		
	}
}
