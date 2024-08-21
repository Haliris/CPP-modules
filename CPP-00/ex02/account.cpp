#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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

int	Account::checkAmount( void ) const
{
	return _totalAmount;
}

void	Account::_displayTimestamp( void )
{
	time_t	timestamp = time(NULL);
	struct tm* localTime = localtime(&timestamp);

	std::cout << "[" << std::setw(4) << std::setfill('0') << (localTime->tm_year + 1900);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_mday);
	std::cout << "_" << std::setw(2) << std::setfill('0') << (localTime->tm_hour);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_min);
	std::cout << std::setw(2) << std::setfill('0') << (localTime->tm_sec);
	std::cout << "] ";
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
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

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
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
	std::cout <<"nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
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
		std::cout <<"nb_withdrawals:" << _nbWithdrawals << std::endl ;
		return true;
	}
}
