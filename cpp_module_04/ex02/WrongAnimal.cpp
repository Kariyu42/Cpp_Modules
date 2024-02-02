/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:12:55 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 20:41:11 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

std::string	WrongAnimal::getType( void ) const {
	return this->_type;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout	<< CYAN << "WrongAnimal " \
				<< this->_type << ": BLIP BLOOP!" \
				<< RESET << std::endl;
}

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout	<< CYAN << "WrongAnimal " \
				<< this->_type << ": has been created!" \
				<< RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout	<< CYAN << "WrongAnimal " \
				<< this->_type << ": has been created!" \
				<< RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout	<< CYAN << "WrongAnimal " \
				<< this->_type << ": has been created!" \
				<< RESET << std::endl;
	*this = copy;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout	<< CYAN << "WrongAnimal " \
				<< this->_type << ": has been destroyed!" \
				<< RESET << std::endl;
	return ;
}
