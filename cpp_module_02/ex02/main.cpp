/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:45:18 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/25 11:27:05 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	/* --- subject main --- */
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << std::endl;
	/* --- my main --- */
	{
		Fixed	a = Fixed(0.1f);
		float	fa = 0.1f;

		Fixed	sumFixed = 0;
		float	sumFloat = 0;

		std::cout << "a = " << a << std::endl;
		std::cout << "fa = " << fa << std::endl;
		for (int i = 0; i < 1000000; i++) {
			sumFixed = sumFixed + a;
			sumFloat = sumFloat + fa;
		}

		std::cout << "sumFixed = " << sumFixed << std::endl;
		std::cout << "sumFloat = " << sumFloat << std::endl;

	}
	return 0;
}
