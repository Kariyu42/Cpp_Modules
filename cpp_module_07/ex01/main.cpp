/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:10:08 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/15 16:09:07 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	printInt(int const &i) {
	std::cout	<< MAGENTA << "{" << i << "}" \
				<< RESET << std::endl;
	return ;
}

void	printChar(char const &c) {
	std::cout	<< CYAN << "{" << c << "}" \
				<< RESET << std::endl;
	return ;
}

void	printString(std::string const &s) {
	std::cout	<< YELLOW << "{" << s << "}" \
				<< RESET << std::endl;
	return ;
}

int	main( void ) {
	int			intArray[MAX_LEN] = {1, 2, 3, 4, 5};
	char		charArray[MAX_LEN] = {'a', 'b', 'c', 'd', 'e'};
	std::string	stringArray[MAX_LEN] = {"one", "two", "three", "four", "five"};

	std::cout	<< GREEN << " ### intArray ### " << RESET << std::endl;
	iter(intArray, MAX_LEN, printInt);

	std::cout	<< GREEN << " ### charArray ### " << RESET << std::endl;
	iter(charArray, MAX_LEN, printChar);

	std::cout	<< GREEN << " ### stringArray ### " << RESET << std::endl;
	iter(stringArray, MAX_LEN, printString);

	return 0;
}
