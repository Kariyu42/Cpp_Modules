/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:37:42 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/14 18:27:39 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

void	identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << GREEN << "identify& function: A" << RESET << std::endl;
	}
	catch (std::exception &bc) {
		std::cerr << RED << "Error: " << bc.what() << RESET << std::endl;
	}

	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << GREEN << "identify& function: B" << RESET << std::endl;
	}
	catch (std::exception &bc) {
		std::cerr << RED << "Error: " << bc.what() << RESET << std::endl;
	}

	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << GREEN << "identify& function: C" << RESET << std::endl;
	}
	catch (std::exception &bc) {
		std::cerr << RED << "Error: " << bc.what() << RESET << std::endl;
	}

	return ;
}

void	identify(Base *p) {
	if (p == NULL) {
		std::cerr << RED << "Error: NULL pointer" << RESET << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p)) {
		std::cout << GREEN << "identify* function: A" << RESET << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << GREEN << "identify* function: B" << RESET << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << GREEN << "identify* function: C" << RESET << std::endl;
		return ;
	}
	std::cerr << RED << "Error: unknown type" << RESET << std::endl;
	return ;
}

Base	*generate( void ) {
	srand((unsigned) time(NULL));
	int i = rand() % 3;
	Base *p = NULL;
	switch (i) {
		case A_TYPE:
			p = new (std::nothrow) A;
			if (p == NULL) {
				std::cerr << RED << "Error: new A" << RESET << std::endl;
				return NULL;
			}
			break ;
		case B_TYPE:
			p = new (std::nothrow) B;
			if (p == NULL) {
				std::cerr << RED << "Error: new B" << RESET << std::endl;
				return NULL;
			}
			break ;
		case C_TYPE:
			p = new (std::nothrow) C;
			if (p == NULL) {
				std::cerr << RED << "Error: new C" << RESET << std::endl;
				return NULL;
			}
			break ;
		default:
			std::cerr << "Error: unknown type" << std::endl;
			return NULL;
	}
	return p;
}

int	main (void ) {
	Base *p = generate();

	identify(p);
	identify(*p);
	
	delete p;

	return 0;
}