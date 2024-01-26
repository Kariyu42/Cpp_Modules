/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:45:18 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/26 16:45:28 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	/* --- tests --- */
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point point(1, 1);
	Point point2(2, 2);
	Point point3(3, 3);
	Point sameAsA(0, 0);
	Point sameAsB(5, 0);
	Point sameAsC(0, 5);

	std::cout << " ### is point in triangle ? ### " << std::endl << "0 == false, 1 == true" << std::endl;
	std::cout << "First test: " << bsp(a, b, c, point) << std::endl;
	std::cout << "point: is inside the triangle ✅" << std::endl;
	std::cout << "Second test: " << bsp(a, b, c, point2) << std::endl;
	std::cout << "point2: is inside the triangle ✅" << std::endl;
	std::cout << "Third test: " << bsp(a, b, c, point3) << std::endl;
	std::cout << "point3: should be outside the triangle ❌" << std::endl;
	std::cout << "Fourth test: " << bsp(a, b, c, sameAsA) << std::endl;
	std::cout << "sameAsA: should be false ❌" << std::endl;
	std::cout << "Fifth test: " << bsp(a, b, c, sameAsB) << std::endl;
	std::cout << "sameAsB: should be false ❌" << std::endl;
	std::cout << "Sixth test: " << bsp(a, b, c, sameAsC) << std::endl;
	std::cout << "sameAsC: should be false ❌" << std::endl;

	return 0;
}
