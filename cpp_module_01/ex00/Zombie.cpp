/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:03:32 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/18 18:38:41 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce( void ) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : _name(name) {return ;}

Zombie::~Zombie() {
	std::cout << _name << ": is destroyed." << std::endl;
	return ;
}
