/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:32:09 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 22:16:43 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout	<< GREEN << "Brain: is created and is now thinking!" \
				<< RESET << std::endl;
	return ;
}

Brain::Brain(Brain const &copy) {
	std::cout	<< GREEN << "Brain: is created and is now thinking!" \
				<< RESET << std::endl;
	*this = copy;
	return ;
}

// Brain	&Brain::operator=(Brain const &other) {
// 	if (this == &other)
// 		return (*this);
// 	this->_ideas = other._ideas;
// 	return (*this);
//}

Brain::~Brain() {
	std::cout	<< RED << "Brain: is dead and can't think anymore!" \
				<< RESET << std::endl;
	return ;
}
