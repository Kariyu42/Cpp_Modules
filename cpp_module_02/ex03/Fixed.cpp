/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:31:27 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/25 15:05:46 by kquetat-         ###   ########.fr       */
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
	_value = roundf(fValue * (1 << _bits));
	return ;
}

Fixed::Fixed(const int iValue) {
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
	_value = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& other) const {
	return _value > other.getRawBits();
}

bool	Fixed::operator<(const Fixed& other) const {
	return _value < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed& other) const {
	return _value >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed& other) const {
	return _value <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed& other) const {
	return _value == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed& other) const {
	return _value != other.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& other) const {
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const {
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const {
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const {
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++( void ) {
	_value++;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed postIncrem(*this);
	postIncrem._value = _value++;
	return postIncrem;
}

Fixed&	Fixed::operator--( void ) {
	_value--;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed postDecrem(*this);
	postDecrem._value = _value--;
	return postDecrem;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
	return ;
}

Fixed::Fixed() : _value(0) {
	return ;
}

Fixed::~Fixed() {
	return ;
}
