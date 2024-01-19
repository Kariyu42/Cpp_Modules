/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:01:18 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 13:07:42 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string	const &Weapon::getType( void ) const {
	return type;
}

void	Weapon::setType(std::string newType) {
	type = newType;
	return ;
}

Weapon::Weapon(std::string weapon) : type(weapon) {return ;}

Weapon::~Weapon() {return ;}