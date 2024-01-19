/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:26:48 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 11:22:34 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main( void ) {
	/* --- origin string --- */
	std::string	 str = "HI THIS IS BRAIN";

	/* --- pointer to the string --- */
	std::string	*stringPTR = &str;

	/* --- reference to the string --- */
	std::string	&stringREF = str;

	/* --- print Memory address --- */
	std::cout << "Memory address of string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	/* --- print values --- */
	std::cout << "String variable: " << str << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << std::endl;
	return 0;
}