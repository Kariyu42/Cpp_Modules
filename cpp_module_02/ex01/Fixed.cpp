/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:31:27 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/24 18:46:28 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float	Fixed::toFloat( void ) const {
	return (float)_value / (1 << _bits);
}

int		Fixed::toInt( void ) const {
	return _value >> _bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
	os << other.toFloat();
	return os;
}

Fixed::Fixed(const float fValue) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(fValue * (1 << _bits));
	return ;
}

Fixed::Fixed(const int iValue) {
	std::cout << "Int constructor called" << std::endl;
	_value = iValue << _bits;
	return ;
}

int	Fixed::getRawBits( void ) const {
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
	return ;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return ;
}
