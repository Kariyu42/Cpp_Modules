/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:05:39 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/17 20:08:42 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals= 0;

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

int	Account::checkAmount( void ) const {
	return _amount;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	timeStamp = time(nullptr);
	std::tm *timeInfo = std::localtime(&timeStamp);

	char	buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo);
	std::cout << "[" << buffer << "] ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) :	_accountIndex(_nbAccounts),
											_amount(initial_deposit),
											_nbDeposits(0),
											_nbWithdrawals(0){
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
	return ;
}

Account::~Account( void ) {
	_nbAccounts--;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
	return ;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount + deposit
				<<  ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" << withdrawal;
	if (_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout	<< ";amount:" << _amount
				<< ";nb_withdrawal:" << _nbWithdrawals << std::endl;
	return true;
}
