/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:39:33 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/27 18:45:08 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("X"), \
					_hitPoints(10), \
					_energyPoints(10), \
					_attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is born !" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), \
										_hitPoints(10), \
										_energyPoints(10), \
										_attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is born !" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &copy) : _name(copy._name), \
											_hitPoints(copy._hitPoints), \
											_energyPoints(copy._energyPoints), \
											_attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " is born !" << std::endl;
	return ;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " is dead !" << std::endl;
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

void	ClapTrap::attack(const std::string &target) {
	std::cout	<< "ClapTrap " << this->_name \
				<< " attacks " << target \
				<< ", causing " << this->_attackDamage \
				<< " points of damage !" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout	<< "ClapTrap " << this->_name \
				<< " takes " << amount \
				<< " damage !" << std::endl;
	this->_hitPoints -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout	<< "ClapTrap " << this->_name \
				<< " heals " << amount \
				<< " health points !" << std::endl;
	return ;
}
