/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:10:08 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/15 15:47:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
	{
		//* Main from the subject
		std::cout << BLUE << " === Subject main === " << RESET << std::endl;
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		//* My main
		std::cout << BLUE << " === My main === " << RESET << std::endl;
		long nbr1 = 42;
		long nbr2 = 21;

		std::cout << GREEN << "nbr1 = " << nbr1 << ", nbr2 = " << nbr2 << RESET << std::endl;
		::swap(nbr1, nbr2);
		std::cout << MAGENTA << "After swap: nbr1 = " << nbr1 << ", nbr2 = " << nbr2 << RESET << std::endl;
		std::cout << "min( nbr1, nbr2 ) = " << ::min(nbr1, nbr2) << std::endl;
		std::cout << "max( nbr1, nbr2 ) = " << ::max(nbr1, nbr2) << std::endl;

		std::string str1 = "Hello";
		std::string str2 = "World";

		std::cout << GREEN << "str1 = " << str1 << ", str2 = " << str2 << RESET << std::endl;
		::swap(str1, str2);
		std::cout << MAGENTA << "After swap: str1 = " << str1 << ", str2 = " << str2 << RESET << std::endl;
		std::cout << "min( str1, str2 ) = " << ::min(str1, str2) << std::endl;
		std::cout << "max( str1, str2 ) = " << ::max(str1, str2) << std::endl;
	}

	return 0;
}
