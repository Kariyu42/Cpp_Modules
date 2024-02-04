/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:19:51 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/03 11:49:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

std::string const	&AMateria::getType( void ) const {
	return this->_type;
}

void	AMateria::use(ICharacter &target) {
	(void)target;
	return ;
}

AMateria::AMateria() : _type("no type") {
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	return ;
}

AMateria::AMateria(AMateria const &copy) {
	*this = copy;
	return ;
}

AMateria	&AMateria::operator=(AMateria const &other) {
	this->_type = other._type;
	return (*this);
}

AMateria::~AMateria() {
	return ;
}
