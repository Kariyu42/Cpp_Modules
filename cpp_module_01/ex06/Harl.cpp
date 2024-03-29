/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:40:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/24 10:39:35 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR_MSG << std::endl << std::endl;
	return ;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING_MSG << std::endl << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO_MSG << std::endl << std::endl;
	return ;
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG_MSG << std::endl << std::endl;
	return ;
}

void	Harl::complain( std::string level ) {
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	Level		lvl = NONE;
	Level		lvlArr[4] = {DEBUG, INFO, WARNING, ERROR};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++) {
		if (level == levels[i]) {
			lvl = lvlArr[i];
			break ;
		}
	}
	switch (lvl) {
		case DEBUG:
			this->debug();
			// fallthrough
		case INFO:
			this->info();
			// fallthrough
		case WARNING:
			this->warning();
			// fallthrough
		case ERROR:
			this->error();
			// fallthrough
		default:
			break ;
	}
}

Harl::Harl() {return ;}

Harl::~Harl() {return ;}
