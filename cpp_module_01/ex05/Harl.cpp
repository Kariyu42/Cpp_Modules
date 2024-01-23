/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:40:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/23 13:04:43 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::error( void ) {
	std::cout << ERROR_MSG << std::endl;
	return ;
}

void	Harl::warning( void ) {
	std::cout << WARNING_MSG << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::cout << INFO_MSG << std::endl;
	return ;
}

void	Harl::debug( void ) {
	std::cout << DEBUG_MSG << std::endl;
	return ;
}

void	Harl::complain( std::string level ) {
	funcPtr	func[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (size_t i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*func[i])();
			return ;
		}
	}
	std::cout << "Wrong level" << std::endl;
	return ;
}

Harl::Harl() {}

Harl::~Harl() {}
