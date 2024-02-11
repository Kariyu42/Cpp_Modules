/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:34:09 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:31:51 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert [literal]" << std::endl;
		return 1;
	}
	std::string	literal = av[1];
	ScalarConverter::convert(literal);
	return 0;
}
