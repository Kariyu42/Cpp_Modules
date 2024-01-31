/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:35:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 16:21:27 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI() {
	std::cout	<< B_BLUE << "DiamondTrap " \
				<< this->_name << ": who am I ?" << std::endl \
				<< B_GREEN << "\tClapTrap: " << ClapTrap::_name << std::endl \
				<< RESET;
	std::cout	<< B_GREEN << "\tHP: " << this->_hitPoints << std::endl \
				<< "\tEP: " << this->_energyPoints << std::endl \
				<< "\tAD: " << this->_attackDamage << std::endl \
				<< RESET;
	return ;
}

void	DiamondTrap::attack(const std::string &target) {
	if (!this->_energyPoints) {
		std::cout	<< RED << "DiamondTrap " << _name \
					<< " has no more energy !" << RESET << std::endl;
		return ;
	}
	ScavTrap::attack(target);
	_energyPoints--;
	return ;
}

DiamondTrap::DiamondTrap() : ClapTrap("X_clap_name"), FragTrap(), ScavTrap() {
	this->_name = "X";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout	<< B_MAGENTA << "DiamondTrap" \
				<< this->_name << ": delivered !" \
				<< RESET << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "clap_name"), FragTrap(name), ScavTrap(name) {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout	<< B_MAGENTA << "DiamondTrap " \
				<< this->_name << ": birthed !" \
				<< RESET << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	std::cout	<< B_MAGENTA << "DiamondTrap " \
				<< this->_name << ": copied !" \
				<< RESET << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap() {
	std::cout	<< B_RED << "DiamondTrap " \
				<< this->_name << ": destroyed !" \
				<< RESET << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other) {
	if (this == &other)
		return (*this);
	this->_name = other._name;
	ClapTrap::_name = other._name + "clap_name";
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout	<< B_MAGENTA << "DiamondTrap " \
				<< this->_name << ": assigned !" \
				<< RESET << std::endl;
	return (*this);
}
