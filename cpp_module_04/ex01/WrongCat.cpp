/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:34:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 20:35:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void	WrongCat::makeSound( void ) const {
	std::cout	<< GREY << "WrongCat " \
				<< this->_type << ": is meowing!" \
				<< RESET << std::endl;
}

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout	<< GREY << "WrongCat " \
				<< this->_type << ": is created and is now INDEPENDANT!" \
				<< RESET << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	std::cout	<< GREY << "WrongCat " \
				<< this->_type << ": is created and is now INDEPENDANT!" \
				<< RESET << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout	<< GREY << "WrongCat " \
				<< this->_type << ": is dead and can't be INDEPENDANT anymore!" \
				<< RESET << std::endl;
	return ;
}
