
#include "Database.hpp"

Database::Database()
{
	_db.open("data.csv");	
	if (!_db)
		throw std::runtime_error("Could not open database.");
}

Database::~Database()
{
}

Database::Database(const Database& copy)
{
    *this = copy;
}

Database& Database::operator=(const Database& copy)
{
    if (this != &copy)
    {
    }
    return *this;
}

Database::Database(const std::string& path)
{
	_db.open("data.csv");	
	_inputFile.open(path);
	if (!_inputFile || !_db)
		throw std::runtime_error("Could not open files.");
}

std::string Database::findDate(const std::string& line) const
{
	std::string match;
	return match;
}

double	Database::extractValue(const std::string& line) const
{
	double	result;

	return result;
}

void	Database::display() const
{
	//validate line
	//find corresponding date
	//perform math operation
	//print
	std::string	line;
	std::getline(_inputFile, line);
	if (line != "date | value")
		throw std::runtime_error("Diplay error: could not recognize file");
	while (std::getline(_inputFile, line))
	{
		try
		{

			std::string 		date;
			double				value;
			date = findDate(line);
			value = extractValue(line);
			std::cout << date << " => " << 
		}
		catch (std::exception &e)
		{
			e.what();
			continue;
		}
	}
}
