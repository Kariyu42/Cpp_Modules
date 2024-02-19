/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:52:10 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/19 16:56:01 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	handleInput(int ac, char **av)
{
	if (ac != 2) {
		std::cout	<< RED "Error: " RESET
					<< CYAN "must use " << av[0] \
					<< " with for e.g \"1 1 +\"" RESET << std::endl;
		return 1;
	}
	std::string		str = av[1];
	if (str.empty()) {
		std::cout	<< RED "Error: " RESET
					<< CYAN "string is empty" RESET << std::endl;
		return 1;
	}
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+' \
				&& str[i] != '-' && str[i] != '*' && str[i] != '/') {
			std::cout	<< RED "Error: " RESET
						<< CYAN "string contains invalid characters" RESET << std::endl;
			return 1;
		}
	}

	return 0;
}

int main(int ac, char **av)
{
	if (handleInput(ac, av) == 1)
		return 1;
	
	std::string	str = av[1];
	try {
		RPN	rpn;
		std::cout << GREEN UNDERLINE "Result:" RESET " " << rpn.execRPN(str) << std::endl;
	} catch (std::exception &e) {
		std::cout << RED "Error: " RESET << e.what() << std::endl;
	} catch (...) {
		std::cout << RED "Error: " RESET << "unknown error" << std::endl;
	}
	return 0;
}
