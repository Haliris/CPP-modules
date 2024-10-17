#include "PmergeMe.hpp"
#include <cstddef>
#include <sstream>

vectorMerge::vectorMerge()
{
}

vectorMerge::~vectorMerge()
{
}

vectorMerge::vectorMerge(const vectorMerge& copy)
{
    *this = copy;
}

vectorMerge& vectorMerge::operator=(const vectorMerge& copy)
{
    if (this != &copy)
    {
    }
    return *this;
}

listMerge::listMerge()
{
}

listMerge::~listMerge()
{
}

listMerge::listMerge(const listMerge& copy)
{
    *this = copy;
}

listMerge& listMerge::operator=(const listMerge& copy)
{
    if (this != &copy)
    {
    }
    return *this;
}

///////////////////
// BOILER PLATES //
///////////////////

void	vectorMerge::sortPairs()
{

}

bool	vectorMerge::checkNum(const std::string& token)
{
	size_t	i = 0;
	
	if (token[0] == '-' || token[0] == '+')
		i++;
	while (i < token.size())
	{
		if (!isdigit(token[i]))
			return false;
		i++;
	}
	return true;
}

bool	vectorMerge::checkDuplicates(int num)
{
	std::vector<std::pair<int, int>>::const_iterator it;

	for (it = _pairs.begin(); it != _pairs.end(); it++)
	{
		if (num == it->first || num == it->second)
			return true;
	}
	return false;
}

vectorMerge::vectorMerge(const std::string&	input)
{
	std::stringstream					inputStream(input);
	std::string							token;
	int									num1, num2, index = 0;

	_pairs.reserve(input.size() / 2); // check correct size
	while (getline(inputStream, token, ' '))
	{
		if (checkNum(token) == false)
			throw std::runtime_error("Error: non numeric argument: " + token);
		if (index % 2 == 0)
			num1 = atoi(token.c_str());
		else if (index % 2 == 1)
		{
			num2 = atoi(token.c_str());
			if (checkDuplicates(num1) == true)
				throw std::runtime_error("Error: no dupliactes allowed: " + token);
			if (checkDuplicates(num2) == true)
				throw std::runtime_error("Error: no dupliactes allowed: " + token);
			_pairs.push_back(std::make_pair(num1, num2));	
		}
	} 
	if (index % 2 == 0)
	{	
		if (checkDuplicates(num1) == true)
			throw std::runtime_error("Error: no dupliactes allowed: " + token);
		_orphan = num1;
	}
}
