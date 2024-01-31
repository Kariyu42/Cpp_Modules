/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:44:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 22:57:30 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

void	Cat::makeSound( void ) const {
	std::cout	<< GREY << this->_type \
				<< ": is meowing!" \
				<< RESET << std::endl;
}

Cat::Cat() : Animal("Cat")
{
	_brain = new (std::nothrow) Brain();
	if (!_brain) {
		std::cerr << "Error: Memory allocation failed." << std::endl;
		return ;
	}
	std::cout	<< GREY << this->_type \
				<< ": is created and is now INDEPENDANT!" \
				<< RESET << std::endl;
	return ;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	std::cout	<< GREY << this->_type \
				<< ": is created and is now INDEPENDANT!" \
				<< RESET << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Cat::~Cat() {
	std::cout	<< RED << this->_type \
				<< ": is dead and can't be INDEPENDANT anymore!" \
				<< RESET << std::endl;
	return ;
}
