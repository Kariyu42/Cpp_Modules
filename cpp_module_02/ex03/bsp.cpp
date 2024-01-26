/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:40:59 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/26 17:20:47 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool	sameCoordinates(Point const p1, Point const p2) {
	return (p1.getX() == p2.getX() && p1.getY() == p2.getY());
}

static bool	isTriangle(Point const p1, Point const p2, Point const p3) {
	Fixed	goodTriangle = (p2.getY() - p1.getY()) * (p3.getX() - p2.getX()) \
							- (p2.getX() - p1.getX()) * (p3.getY() - p2.getY());
	if (goodTriangle == 0)
		return false;
	return true;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	if (sameCoordinates(a, b) || sameCoordinates(a, c) || sameCoordinates(b, c)) {
		std::cout << "Error: two points are the same" << std::endl;
		return false;
	}
	if (sameCoordinates(a, point) || sameCoordinates(b, point) || sameCoordinates(c, point)) {
		std::cout << "Error: point is the same as one of the three points" << std::endl;
		return false;
	}
	if (!isTriangle(a, b, c)) {
		std::cout << "Error: the three points does not form a triangle" << std::endl;
		return false;
	}

	Fixed	denominator = (b.getY() - c.getY()) * (a.getX() - c.getX()) \
							+ (c.getX() - b.getX()) * (a.getY() - c.getY());
	Fixed	alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) \
							+ (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
	Fixed	beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) \
							+ (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
	Fixed	gamma = Fixed(1) - alpha - beta;

	if (alpha > Fixed(0) && alpha < Fixed(1) \
		&& beta > Fixed(0) && beta < Fixed(1) \
		&& gamma > Fixed(0) && gamma < Fixed(1))
		return true;
	return false;
}
