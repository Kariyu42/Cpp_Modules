/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:34:06 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/24 14:18:38 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 3) {
		std::cout	<< RED BOLD << "Error: " << RESET
					<< "Not enough arguments." << std::endl;
		return 1;
	}
	try {
		PmergeMe	runAlgo(ac, av);
	} catch (std::exception &e) {
		std::cout	<< RED BOLD << "Error: " << RESET
					<< e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cout	<< RED BOLD << "Error: " << RESET
					<< "An unknown error occurred." << std::endl;
		return 1;
	}
	return 0;
}
