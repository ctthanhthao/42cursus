/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:26:47 by thchau            #+#    #+#             */
/*   Updated: 2025/10/05 16:39:18 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <sstream>

static std::vector<std::string> closeLogs;
// -------------- Helper: static object to print logs at program exit--------
struct CloseLogPrinter
{
	~CloseLogPrinter()
	{
		if (!closeLogs.empty())
		{
			std::vector<std::string>::reverse_iterator it;
			for (it = closeLogs.rbegin(); it != closeLogs.rend();++it)
				std::cout << *it << std::endl;
		}
	}
};
static CloseLogPrinter printer;

// ---------------------------- END -----------------------------------------
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//======================== Constructor and Destructor ========================
Account::Account(int initial_deposit)
	: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	std::ostringstream oss;
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	oss << "["
		<< (ltm->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
		<< std::setw(2) << std::setfill('0') << ltm->tm_hour
		<< std::setw(2) << std::setfill('0') << ltm->tm_min
		<< std::setw(2) << std::setfill('0') << ltm->tm_sec
		<< "]"
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed";
	closeLogs.push_back(oss.str());
//	_nbAccounts--;
}
//============================= END =========================================
void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	std::cout << "["
			  << (ltm->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
			  << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
			  << std::setw(2) << std::setfill('0') << ltm->tm_hour
			  << std::setw(2) << std::setfill('0') << ltm->tm_min
			  << std::setw(2) << std::setfill('0') << ltm->tm_sec
			  << "]";
}

int	Account::getNbAccounts( void )
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

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() 
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int pAmount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << pAmount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << " index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		int pAmount = _amount;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << " index:" << _accountIndex
			  << ";p_amount:" << pAmount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbDeposits << std::endl;
		return true;
	}
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}