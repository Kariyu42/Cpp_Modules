/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:09:28 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/30 13:55:34 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

void	FragTrap::highFivesGuys( void ) {
	std::cout	<< B_YELLOW << "FragTrap " \
				<< this->_name << ": high fives !" \
				<< RESET << std::endl;
	return ;
}

void	FragTrap::checkStatus( void ) {
	std::cout	<< B_BLUE << "FragTrap " \
				<< this->_name << ": status:" << std::endl << B_GREEN \
				<< "\tHP: " << this->_hitPoints << std::endl \
				<< "\tEP: " << this->_energyPoints << std::endl \
				<< "\tAD: " << this->_attackDamage << std::endl \
				<< RESET;
	return ;
}

FragTrap::FragTrap() : ClapTrap() {
	std::cout	<< B_MAGENTA << "FragTrap " \
				<< this->_name << ": birthed !" \
				<< RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout	<< B_MAGENTA << "FragTrap " \
				<< this->_name << ": birthed !" \
				<< RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
	std::cout	<< B_MAGENTA << "FragTrap " \
				<< this->_name << ": birthed !" \
				<< RESET << std::endl;
	return ;
}

FragTrap::~FragTrap() {
	std::cout	<< B_RED << "FragTrap " \
				<< this->_name << ": perished !" \
				<< RESET << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &other) {
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}
