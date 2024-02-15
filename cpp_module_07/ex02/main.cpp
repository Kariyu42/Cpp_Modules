/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:31:51 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/15 17:41:30 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int	subjectMain() {

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	return 0;
}

void	myMain( void ) {
	//* Defined size for the array
	std::cout << YELLOW << " --- Defined size for the array --- " << RESET << std::endl;
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); i++) {
		numbers[i] = i;
		std::cout	<< "numbers" << BLUE << "[" << GREEN << i << BLUE \
					<< "] = " << CYAN << numbers[i] \
					<< RESET << std::endl;
	}

	//* Copy constructor
	std::cout << YELLOW << " --- Copy constructor --- " << RESET << std::endl;
	Array<int> copy(numbers);
	for (unsigned int i = 0; i < copy.size(); i++) {
		std::cout	<< "copy" << BLUE << "[" << GREEN << i << BLUE \
					<< "] = " << CYAN << copy[i] \
					<< RESET << std::endl;
	}

	//* Assignment operator
	std::cout << YELLOW << " --- Assignment operator --- " << RESET << std::endl;
	Array<int> assign;
	assign = numbers;
	for (unsigned int i = 0; i < assign.size(); i++) {
		std::cout	<< "assign" << BLUE << "[" << GREEN << i << BLUE \
					<< "] = " << CYAN << assign[i] \
					<< RESET << std::endl;
	}

	//* Out of range
	std::cout << RED << " --- Out of range --- " << RESET << std::endl;
	try {
		std::cout << CYAN << "Trying to access numbers[-1]... " << RESET << std::endl;
		numbers[-1] = 0;
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr << RED << "Error: Unknown exception" << RESET << std::endl;
	}
	try {
		numbers[4] = 42;
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr << RED << "Error: Unknown exception" << RESET << std::endl;
	}
	std::cout	<< YELLOW << " === Printing the array to check... === " << RESET << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cout	<< "numbers" << BLUE << "[" << GREEN << i << BLUE \
					<< "] = " << CYAN << numbers[i] \
					<< RESET << std::endl;
	}

	//* Test with a string
	std::cout << YELLOW << " --- Test with a string --- " << RESET << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	for (unsigned int i = 0; i < strings.size(); i++) {
		std::cout	<< "strings" << BLUE << "[" << GREEN << i << BLUE \
					<< "] = " << CYAN << strings[i] \
					<< RESET << std::endl;
	}

	//* Test with a float
	std::cout << YELLOW << " --- Test with a float --- " << RESET << std::endl;
	Array<float> floats(3);
	floats[0] = 3.14;
	floats[1] = 42.0;
	floats[2] = 0.0;
	for (unsigned int i = 0; i < floats.size(); i++) {
		std::cout	<< "floats" << BLUE << "[" << GREEN << i << BLUE \
					<< "] = " << CYAN << floats[i] \
					<< RESET << std::endl;
	}

	//* Test with int but with no size
	std::cout << YELLOW << " --- Test with int but with no size --- " << RESET << std::endl;
	Array<int> noSize;
	try {
		std::cout << CYAN << "Trying to access noSize[0]... " << RESET << std::endl;
		noSize[0] = 42;
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr << RED << "Error: Unknown exception" << RESET << std::endl;
	}
	return ;
}

int main(int, char**) {
	if (subjectMain()) {
		std::cerr << "Error in subjectMain" << std::endl;
		return 1;
	}

	std::cout << MAGENTA << " === myMain === " << RESET << std::endl;
	myMain();

	return 0;
}
