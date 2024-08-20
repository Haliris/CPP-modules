#include "Account.hpp"
#include <iostream>

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
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
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
	std::cout <<"nb_deposits:" << _nbDeposits << ";";
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
		std::cout <<"nb_withdrawals:" << _nbWithdrawals << ";";
		return true;
	}
}
