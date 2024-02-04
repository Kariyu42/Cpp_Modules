/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:41:35 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/03 11:45:28 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

AMateria	*Ice::clone( void ) const {
	AMateria	*clone = new (std::nothrow) Ice(*this);
	if (!clone) {
		std::cout << "Memory allocation failed" << std::endl;
		exit(1);
	}
	return (clone);
}

void	Ice::use(ICharacter &target) {
	std::cout	<< "* shoots an ice bolt at " \
				<< target.getName() << " *" \
				<< std::endl;
	return ;
}

Ice::Ice() : AMateria("ice") {
	return ;
}

Ice::Ice(Ice const &copy) : AMateria(copy) {
	return ;
}

Ice	&Ice::operator=(Ice const &other) {
	this->_type = other._type;
	return (*this);
}

Ice::~Ice() {
	return ;
}
