
#include "BitcoinExchange.hpp"

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

Database::Database(const std::string& path) : _argPath(path)
{
	std::ifstream fileDb, fileArg;

	fileDb.open(DB_PATH);	
	fileArg.open(path.c_str());
	if (!fileDb || !fileArg)
		throw std::runtime_error("Could not open files.");
	
	std::string	line;
	std::getline(fileDb, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: database unrecognized");
	while (std::getline(fileDb, line))
	{
		size_t	sep = line.find(",");
		if (sep == line.size())
			throw std::runtime_error("Error: could not find separator in database file");
		char	*end;
		_db[line.substr(0, sep)] = std::strtod(line.substr(sep + 1, line.size() - 1).c_str(), &end);
		if (end == line.substr(sep + 1, line.size() - 1).c_str())
			std::cerr << "Error: could not parse value of key:" << line.substr(0, sep - 1) << std::endl;
	}
}

uint32_t	Database::convertDate(const std::string& date) const
{
	std::string	dateCopy = date;
	uint32_t	value = 0;
	uint32_t 	sepNum = 0;
	
	for (size_t i = 0; i < dateCopy.size(); i++)
	{
		if (dateCopy[i] == '-')
		{
			dateCopy.erase(i, 1);
			sepNum++;
		}
	}
	if (sepNum != 2)
		throw std::runtime_error("Error: could not convert date value => " + date);
	value = std::atoi(dateCopy.c_str());
	return value;
}

std::string Database::findDate(const std::string& line) const
{
	std::string match;
	std::string date;
	uint32_t	dateValue;
	uint32_t	diff = INT_MAX;

	size_t sep = line.find("|");
	if (sep == line.size())
		throw std::runtime_error("Error: missing separator in input line");
	date = line.substr(0, sep - 1);
	dateValue = convertDate(date);
	match = date;
	if (dateValue >= 20220329)
		return _db.rbegin()->first;
	if (dateValue <= 20090102)
		return _db.begin()->first;
	std::map<std::string, double>::const_iterator	it = _db.begin();
	while (it != _db.end())
	{
		uint32_t dbDate = convertDate(it->first);
		if (dbDate - dateValue < diff)
		{
			match = it->first;
			diff = dbDate - dateValue;
		}
		it++;
	}
	return match;
}

double	Database::extractValue(const std::string& line) const
{
	double	result;
	
	size_t	sep = line.find('|');
	if (sep == std::string::npos)
	{
		throw std::runtime_error("Error: bad input => " + line);
	}
	sep++;
	while (line[sep] && isspace(line[sep]))
		sep++;
	if (line[sep] == '-' || line[sep] == '+')
	{
		if (line[sep] == '-')
			throw std::runtime_error("Error: not a positive number");
		sep++;
	}
	if (!isdigit(line[sep]))
		throw std::runtime_error("Error: bad input => " + line);
	result = std::strtod(line.substr(sep, line.size() - 1).c_str(), NULL);
	if (result > 1000)
		throw std::runtime_error("Error: too large a number");
	return result;
}

void	Database::display() const
{
	std::ifstream fileDb, fileArg;
	std::string	line;

	fileDb.open(DB_PATH);	
	fileArg.open(_argPath.c_str());
	if (!fileDb || !fileArg)
		throw std::runtime_error("Could not open files.");
	std::getline(fileArg, line);
	if (line != "date | value")
		throw std::runtime_error("Diplay error: could not recognize file");
	while (std::getline(fileArg, line))
	{
		try
		{
			std::string 		date;
			double				initialValue;
			double				value;

			date = findDate(line);
			initialValue = _db.at(date);
			value = extractValue(line);
			std::cout << date << " => " << initialValue << " = " << value*initialValue << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
}
