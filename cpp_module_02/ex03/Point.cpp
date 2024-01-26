/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:41:06 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/25 18:27:26 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

const Fixed& Point::getY() const {
	return _y;
}

const Fixed& Point::getX() const {
	return _x;
}

Point::Point( const float x, const float y ) : _x(x), _y(y) {
	return ;
}

Point& Point::operator=(const Point& other) {
	if (this != &other) {
		(Fixed)this->_x = other._x;
		const_cast<Fixed&>(this->_y) = other._y;
	}

	return *this;
}

// init constructor copy
Point::Point( const Point& other ) : _x(other._x), _y(other._y) {
	return ;
}

Point::Point( void ) : _x(0), _y(0) {
	return ;
}

Point::~Point( void ) {
	return ;
}
