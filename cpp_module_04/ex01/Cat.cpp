/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:44:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/02 11:05:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

void	Cat::makeSound( void ) const {
	std::cout	<< GREY << this->_type \
				<< ": is meowing!" \
				<< RESET << std::endl;
}

void	Cat::printIdeas( void ) const {
	std::string	*ideas = this->_brain->getIdeas();
	for (int i = 0; i < 100; i++) {
		std::cout	<< GREY << this->_type \
					<< " is thinking: " << ideas[i] \
					<< RESET << std::endl;
	}
}

Cat::Cat() : Animal("Cat") {
	this->_brain = new (std::nothrow) Brain("Cat");
	if (!this->_brain)
	{
		std::cerr	<< RED \
					<< "Error: Memory allocation failed." \
					<< RESET << std::endl;
		exit(1);
	}
	std::cout	<< GREY << this->_type \
				<< ": is created and is now INDEPENDANT!" \
				<< RESET << std::endl;
	return ;
}

Cat::Cat(Cat const &copy) : Animal(copy._type) {
	this->_brain = new (std::nothrow) Brain(*copy._brain);
	if (!this->_brain)
	{
		std::cerr	<< RED \
					<< "Error: Memory allocation failed." \
					<< RESET << std::endl;
		exit(1);
	}
	std::cout	<< GREY << this->_type \
				<< ": is created and is now INDEPENDANT!" \
				<< RESET << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &other) {
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

Cat::~Cat() {
	delete this->_brain;
	std::cout	<< RED << this->_type \
				<< ": is dead and can't be INDEPENDANT anymore!" \
				<< RESET << std::endl;
	return ;
}
