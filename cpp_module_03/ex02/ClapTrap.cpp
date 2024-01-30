/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:39:33 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/29 13:11:50 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("X"), \
					_hitPoints(10), \
					_energyPoints(10), \
					_attackDamage(0)
{
	std::cout	<< PURPLE << "ClapTrap " \
				<< this->_name << ": is born !" \
				<< RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), \
										_hitPoints(10), \
										_energyPoints(10), \
										_attackDamage(0)
{
	std::cout	<< PURPLE << "ClapTrap " \
				<< this->_name << ": is born !" \
				<< RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &copy) : _name(copy._name), \
											_hitPoints(copy._hitPoints), \
											_energyPoints(copy._energyPoints), \
											_attackDamage(copy._attackDamage)
{
	std::cout	<< PURPLE << "ClapTrap " \
				<< this->_name << ": is born !" \
				<< RESET << std::endl;
	return ;
}

ClapTrap::~ClapTrap() {
	std::cout	<< CYAN << "ClapTrap " \
				<< this->_name << ": is dead !" \
				<< RESET << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

std::string	ClapTrap::getName( void ) const {
	return this->_name;
}

int	ClapTrap::getHitPoints( void ) const {
	return this->_hitPoints;
}

int	ClapTrap::getEnergyPoints( void ) const {
	return this->_energyPoints;
}

int	ClapTrap::getAttackDamage( void ) const {
	return this->_attackDamage;
}

void	ClapTrap::setAttackDamage(int amount) {
	this->_attackDamage = amount;
	return ;
}

void	ClapTrap::attack(const std::string &target) {
	if (!this->_energyPoints) {
		std::cout	<< "ClapTrap " << this->_name \
					<< ": has no more energy !" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout	<< RED << "ClapTrap " << this->_name \
				<< ": attacks " << target \
				<< ", causing " << this->_attackDamage \
				<< " points of damage !" << RESET << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout	<< RED << "ClapTrap " << this->_name \
					<< ": is already dead !" << RESET << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout	<< RED << "ClapTrap " << this->_name \
				<< ": takes " << amount \
				<< " damage !" << RESET << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_energyPoints) {
		std::cout	<< YELLOW << "ClapTrap " << this->_name \
					<< ": has no more energy !" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0) {
		std::cout	<< YELLOW << "ClapTrap " << this->_name \
					<< ": is already dead !" << RESET << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout	<< GREEN << "ClapTrap " << this->_name \
				<< ": heals " << amount \
				<< " hit points !" << RESET << std::endl;
	return ;
}

void	ClapTrap::checkStatus( void ) const {
	std::cout	<< BLUE << "ClapTrap " << this->_name \
				<< ": has " << this->_hitPoints \
				<< " hit points and " << this->_energyPoints \
				<< " energy points !" << RESET << std::endl;
	return ;
}
