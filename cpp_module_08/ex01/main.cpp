/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:33:18 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/17 15:18:14 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	printVector(std::vector<int> v) {
	std::cout << BOLD << "Vector: " << MAGENTA << "{ " << RESET ;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << BLUE << "[" << YELLOW << *it << BLUE << "] " << RESET;
	}
	std::cout << BOLD << MAGENTA << "}" << RESET << std::endl;
}

void	subjectMain( void ) {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return ;
}

void	testMain( void ) {
	Span	span = Span(V_LENGTH);

	try {
		span.addNumber(1);
		printVector(span.getVector());
		span.addNumber(6);
		printVector(span.getVector());
		span.addNumber(32);
		printVector(span.getVector());
		span.addNumber(-9);
		printVector(span.getVector());
		span.addNumber(67);
		printVector(span.getVector());
		span.addNumber(42); //! This line will throw an exception if V_LENGTH is < 6
	}
	catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << BOLD << " === Our final vector === " << RESET << std::endl;
	printVector(span.getVector());

	try {
		std::cout	<< YELLOW << BOLD << "Shortest span: " \
					<< GREEN << span.shortestSpan() \
					<< RESET << std::endl;
		std::cout	<< YELLOW << BOLD << "Longest span: " \
					<< GREEN << span.longestSpan() \
					<< RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr	<< RED << "Error: " << e.what() \
					<< RESET << std::endl;
	}

	return ;
}

void	testWithBigVector( void ) {

	Span	span = Span(V2_LENGTH);
	std::vector<int>	v;

	srand(time(NULL));
	for (int i = 0; i < V2_LENGTH; i++) {
		v.push_back(rand() % 10000);
	}

	try {
		span.addNNumbers(v.begin(), v.end());
		std::cout	<< YELLOW << BOLD \
					<< " === Vector after filling with range of iterators === " \
					<< RESET << std::endl;
		printVector(span.getVector());
	}
	catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	try {
		std::cout	<< YELLOW << BOLD << "Shortest span: " \
					<< GREEN << span.shortestSpan() \
					<< RESET << std::endl;
		std::cout	<< YELLOW << BOLD << "Longest span: " \
					<< GREEN << span.longestSpan() \
					<< RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr	<< RED << "Error: " << e.what() \
					<< RESET << std::endl;
	}

	return ;
}

void	testingOneNumber( void ) {
	Span	span = Span(1);
	
	try {
		span.addNumber(42);
		printVector(span.getVector());
		std::cout	<< YELLOW << BOLD << "Shortest span: " \
					<< GREEN << span.shortestSpan() \
					<< RESET << std::endl;
		std::cout	<< YELLOW << BOLD << "Longest span: " \
					<< GREEN << span.longestSpan() \
					<< RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr	<< RED << "Error: " << e.what() \
					<< RESET << std::endl;
	}

	return ;
}

int	main( void ) {

	std::cout << BOLD << BLUE << " === Subject main === " << RESET << std::endl;
	subjectMain();
	std::cout << BOLD << BLUE << " === END === " << RESET << std::endl;

	std::cout << BOLD << BLUE << " === testMain === " << RESET << std::endl;
	testMain();
	std::cout << BOLD << BLUE << " === END === " << RESET << std::endl;

	std::cout << BOLD << BLUE << " === testWithBigVector === " << RESET << std::endl;
	testWithBigVector();
	std::cout << BOLD << BLUE << " === END === " << RESET << std::endl;

	std::cout << BOLD << BLUE << " === Test with only one number === " << RESET << std::endl;
	testingOneNumber();
	std::cout << BOLD << BLUE << " === END === " << RESET << std::endl;

	return 0;
}
