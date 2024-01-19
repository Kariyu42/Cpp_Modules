/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:18:28 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 13:18:18 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

void	HumanA::attack( void ) const {
	std::cout << _name << " attacks with their " << _myWeapon.getType() << std::endl;
	return ;
}

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _myWeapon(weapon) {return ;}

HumanA::~HumanA() {return ;}
