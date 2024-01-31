/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:10 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 21:14:25 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

void	Dog::makeSound( void ) const {
	std::cout	<< BROWN << this->_type \
				<< ": is barking!" \
				<< RESET << std::endl;
}

Dog::Dog() : Animal("Dog")
{
	std::cout	<< BROWN << this->_type \
				<< ": is created and wants to be hugged!" \
				<< RESET << std::endl;
	return ;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout	<< BROWN << this->_type \
				<< ": is created and wants to be hugged!" \
				<< RESET << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Dog::~Dog() {
	std::cout	<< RED << this->_type \
				<< ": is dead and can't be hugged anymore!" \
				<< RESET << std::endl;
	return ;
}
