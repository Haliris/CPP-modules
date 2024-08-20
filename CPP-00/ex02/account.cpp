#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

	static void	displayAccountsInfos( void );

int	Account::getNbAccounts ( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp( void )
{
	time_t	timestamp = time(NULL);
	struct tm* localTime = localtime(&timestamp);

	std::cout << "[" << std::setw(4) << std::setfill('0') << (localTime->tm_year + 1900);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_mday);
	std::cout << "_" << std::setw(2) << std::setfill('0') << (localTime->tm_mday);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_mday);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_mday);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_mday);
	std::cout << "] ";
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	makeDeposit(initial_deposit);
	_accountIndex = this->_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	Account::_nbAccounts--;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ";" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";";
	std::cout <<"p_amount:" << _amount << ";";
	_nbDeposits++;
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout <<"deposit:" << deposit << ";";
	std::cout <<"amount:" << _amount << ";";
	std::cout <<"nb_deposits:" << _nbDeposits << ";" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		std::cout << ":refused" << std::endl;
		return false;
	}
	else
	{
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout <<"withdrawal:" << withdrawal << ";";
		std::cout <<"amount:" << _amount << ";";
		std::cout <<"nb_withdrawals:" << _nbWithdrawals << std::endl << ";";
		return true;
	}
}
