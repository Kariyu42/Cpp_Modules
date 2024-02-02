/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:10 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/02 11:02:39 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

void	Dog::makeSound( void ) const {
	std::cout	<< BROWN << this->_type \
				<< ": is barking!" \
				<< RESET << std::endl;
}

void	Dog::printIdeas( void ) const {
	std::string	*ideas = this->_brain->getIdeas();
	for (int i = 0; i < 100; i++) {
		std::cout	<< BROWN << this->_type \
					<< " is thinking: " << ideas[i] \
					<< RESET << std::endl;
	}
}

Dog::Dog() : Animal("Dog") {
	this->_brain = new (std::nothrow) Brain("Dog");
	if (!this->_brain)
	{
		std::cerr	<< RED \
					<< "Error: Memory allocation failed." \
					<< RESET << std::endl;
		exit(1);
	}
	std::cout	<< BROWN << this->_type \
				<< ": is created and wants to be hugged!" \
				<< RESET << std::endl;
	return ;
}

Dog::Dog(Dog const &copy) : Animal(copy._type) {
	this->_brain = new (std::nothrow) Brain(*copy._brain);
	if (!this->_brain)
	{
		std::cerr	<< RED \
					<< "Error: Memory allocation failed." \
					<< RESET << std::endl;
		exit(1);
	}
	std::cout	<< BROWN << this->_type \
				<< ": is created and wants to be hugged!" \
				<< RESET << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &other) {
	if (this == &other)
		return (*this);
	delete this->_brain;
	this->_brain = new (std::nothrow) Brain(*other._brain);
	if (!this->_brain)
	{
		std::cerr	<< RED \
					<< "Error: Memory allocation failed." \
					<< RESET << std::endl;
		exit(1);
	}
	this->_type = other._type;
	return (*this);
}

Dog::~Dog() {
	delete this->_brain;
	std::cout	<< RED << this->_type \
				<< ": is dead and can't be hugged anymore!" \
				<< RESET << std::endl;
	return ;
}
