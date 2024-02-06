/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:46:19 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/06 14:00:00 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

AMateria	*Cure::clone( void ) const {
	AMateria	*clone = new (std::nothrow) Cure(*this);
	if (!clone) {
		std::cout << "Memory allocation failed" << std::endl;
		exit(1);
	}
	return (clone);
}

void	Cure::use(ICharacter &target) {
	std::cout	<< "* heals " \
				<< target.getName() << "'s wounds *" \
				<< std::endl;
	return ;
}

Cure::Cure() : AMateria("cure") {
	return ;
}

Cure::Cure(Cure const &copy) : AMateria(copy) {
	return ;
}

Cure	&Cure::operator=(Cure const &other) {
	this->_type = other._type;
	return (*this);
}

Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
	return ;
}
