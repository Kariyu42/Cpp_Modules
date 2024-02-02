/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:18:10 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/02 12:23:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	Animal::getType( void ) const {
	return this->_type;
}

void	Animal::makeSound( void ) const {
	std::cout	<< CYAN << "Animal " << this->_type \
				<< " tries to make a sound but its vocal cords are not working !" \
				<< RESET << std::endl;
}

Animal::Animal() : _type("X")
{
	std::cout << PURPLE << "Animal " << this->_type << ": is born !" << RESET << std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << PURPLE << "Animal " << this->_type << ": is born !" << RESET << std::endl;
	return ;
}

Animal::Animal(Animal const &copy) : _type(copy._type)
{
	std::cout << PURPLE << "Animal " << this->_type << ": is born !" << RESET << std::endl;
	return ;
}

Animal	&Animal::operator=(Animal const &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << RED << "Animal " << this->_type << ": is dead !" << RESET << std::endl;
	return ;
}
