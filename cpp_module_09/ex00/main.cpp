/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:52:10 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/19 11:57:13 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	handleInput(int ac, char **av)
{
	if (ac != 2) {
		std::cout	<< RED << "Error: could not open file" \
					<< RESET << std::endl;
		return 1;
	}

	std::string arg = av[1];
	if (arg.empty()) {
		std::cout	<< RED << "Error: " << arg << " is empty" << RESET << std::endl;
		return 1;
	}

	std::ifstream file(arg.c_str());
	if (!file.is_open()) {
		std::cout	<< RED << "Error: " << "File " << arg \
					<< " could not be opened" << RESET << std::endl;
		return 1;
	}
	file.close();
	if (file.is_open()) {
		std::cout	<< RED << "Error: " << "File " << arg \
					<< " could not be closed" << RESET << std::endl;
		return 1;
	}

	return 0;
}

int main(int ac, char **av)
{
	if (handleInput(ac, av) == 1)
		return 1;

	try {
		BitcoinExchange btcExchange;

		btcExchange.initData("data.csv");
		btcExchange.showExchange(av[1]);

	} catch (std::exception &e) {
		std::cerr	<< RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	} catch (...) {
		std::cerr	<< RED << "Error: " << "Unknown exception" << RESET << std::endl;
		return 1;
	}
	
	return 0;
}
