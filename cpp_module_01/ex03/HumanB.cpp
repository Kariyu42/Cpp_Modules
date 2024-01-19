/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:18:23 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 13:33:56 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon& weapon) {
	_myWeapon = &weapon;
	return ;
}

void	HumanB::attack( void ) const {
	if (!_myWeapon)
		std::cout << _name << " attacks with their bare hands" << std::endl;
	else
		std::cout << _name << " attacks with their " << _myWeapon->getType() << std::endl;
	return ;
}

HumanB::HumanB(std::string name) : _name(name) {
	_myWeapon = NULL;
	return ;
}

HumanB::~HumanB() {return ;}