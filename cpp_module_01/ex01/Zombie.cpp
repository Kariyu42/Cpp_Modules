/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:03:32 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/18 19:53:07 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce( void ) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string& str) {
	_name = str;
	return ;
}

Zombie::Zombie() {return ;}

Zombie::~Zombie() {
	std::cout << _name << ": is destroyed." << std::endl;
	return ;
}
