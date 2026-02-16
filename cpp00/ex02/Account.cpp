/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:40:55 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/04 18:11:24 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// On initialise les fonctions statiques
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


/*
-std::time_t : type pour stocker un timestamp (nombre de secondes depuis le 1er janvier 1970)
-std::time(NULL) : fonction qui retourne le timestamp actuel
-time_ptr contient maintenant le nombre de secondes depuis 1970*/

/*
std::localtime() : convertit le timestamp en structure tm (time)
&now : on passe l'adresse du timestamp
ltm : pointeur vers une structure contenant :
tm_year : années depuis 1900
tm_mon : mois (0-11, donc janvier = 0)
tm_mday : jour du mois (1-31)
tm_hour : heure (0-23)
tm_min : minutes (0-59)
tm_sec : secondes (0-59)*/

void	Account::_displayTimestamp( void )
{
	std::time_t	time_ptr;
	time_ptr = std::time(NULL);

	std::tm *ltm = std::localtime(&time_ptr);

	std::cout << "["
			  << (1900 + ltm->tm_year)
			  << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon)
			  << std::setw(2) << ltm->tm_mday
			  << "_"
			  << std::setw(2) << ltm->tm_hour
			  << std::setw(2) << ltm->tm_min
			  << std::setw(2) << ltm->tm_sec
			  << "]";
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount = _totalAmount + initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl ;

	return;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl ;
	_nbAccounts--;
	_totalAmount = _totalAmount - _amount;

	return;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";"
			  << "total:" << _totalAmount << ";"
			  << "deposits:" << _totalNbDeposits << ";"
			  << "withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals
			  << std::endl;
}


void	Account::makeDeposit( int deposit )
{
	int	p_amount = _amount;

	_amount = _amount + deposit;
	_nbDeposits++;
	_totalAmount = _totalAmount + deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits
			  << std::endl;
	return;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = _amount;

	_amount = _amount - withdrawal;
	if (_amount < 0)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";"
			 	  << "p_amount:" << p_amount << ";"
				  << "withdrawal:refused"
				  << std::endl;
		_amount = p_amount;
		return false;
	}

	_nbWithdrawals++;
	_totalAmount = _totalAmount - withdrawal;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount << ";"
			  << "nb_withdrawals:" << _nbWithdrawals
			  << std::endl;

	return true;
}


