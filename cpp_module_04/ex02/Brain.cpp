/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:32:09 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/02 10:34:35 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string *Brain::getIdeas( void ) {
	return this->_ideas;
}

void	Brain::setIdeas( std::string ideas ) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas;
	return ;
}

Brain::Brain() {
	setIdeas("Got no ideas!");
	std::cout	<< ROSE << "Brain: is created and is now thinking!" \
				<< RESET << std::endl;
	return ;
}

Brain::Brain(std::string animalType) {
	if (animalType == "Dog")
		setIdeas("I love bones!");
	else if (animalType == "Cat")
		setIdeas("I love fish!");
	std::cout	<< ROSE << "Brain: is created and is now thinking!" \
				<< RESET << std::endl;
	return ;
}

Brain::Brain(Brain const &copy) {
	std::cout	<< ROSE << "Brain: is created and is now thinking!" \
				<< RESET << std::endl;
	*this = copy;
	return ;
}

Brain	&Brain::operator=(Brain const &other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout	<< RED << "Brain: is dead and can't think anymore!" \
				<< RESET << std::endl;
	return ;
}
