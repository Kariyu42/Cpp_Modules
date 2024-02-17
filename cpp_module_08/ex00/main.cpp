/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:33:18 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/16 20:52:37 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	printVector(std::vector<int> &container) {
	std::vector<int>::iterator	it;

	std::cout	<< "Container: ";
	for (it = container.begin(); it != container.end(); it++) {
		std::cout	<< *it;
		if (it + 1 != container.end())
			std::cout	<< ", ";
	}
	std::cout	<< std::endl;
}

int	main( void ) {
	std::vector<int>	container;
	int					n;

	container.push_back(1);
	// printVector(container);
	container.push_back(2);
	container.push_back(3);
	// printVector(container);
	container.push_back(4);
	container.push_back(5); //* function to add elements to the end of the vector
	// printVector(container);

	n = 3;
	try {
		std::cout	<< GREEN << "Trying to find " << n << " in the container" \
					<< RESET << std::endl;
		std::cout	<< BOLD << BLUE << "RESULT: " << easyfind(container, n) \
					<< RESET << std::endl; //* call to the easyfind function
	} catch (std::exception &e) {
		std::cout	<< RED << BOLD << n << " not found" \
					<< RESET << std::endl;
	}
	n = 6;
	try {
		std::cout	<< GREEN << "Trying to find " << n << " in the container" \
					<< RESET << std::endl;
		std::cout	<< BOLD << BLUE << "RESULT: " << easyfind(container, n) \
					<< RESET << std::endl; //* call to the easyfind function
	} catch (std::exception &e) {
		std::cout	<< RED << BOLD << n << " not found" \
					<< RESET << std::endl;
	}
	std::cout	<< YELLOW << "Removing the last element from the container" \
				<< RESET << std::endl;
	container.pop_back(); //* function to remove the last element from the vector
	n = 5;
	try {
		std::cout	<< GREEN << "Trying to find " << n << " in the container" \
					<< RESET << std::endl;
		std::cout	<< BOLD << BLUE << "RESULT: " << easyfind(container, n) \
					<< RESET << std::endl; //* call to the easyfind function
	} catch (std::exception &e) {
		std::cout	<< RED << BOLD << n << " not found" \
					<< RESET << std::endl;
	}

	container.clear(); //* function to remove all elements from the vector
	//* print after clearing the vector
	// printVector(container);
	return 0;
}
