/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:11:50 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 18:02:42 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void ) {

	Data		data;
	Data		*ptr;
	uintptr_t	raw;

	data.str = "String variable of Data struct";
	data.i = 42;
	data.c = 'A';

	std::cout << ORANGE << " === Data struct === " << RESET << std::endl;
	std::cout	<< ORANGE << "data.str: " << data.str << std::endl \
				<< "data.i: " << data.i << std::endl \
				<< "data.c: " << data.c << RESET << std::endl;
	
	raw = Serializer::serialize(&data);
	// std::cout << "raw: " << raw << std::endl;
	
	ptr = Serializer::deserialize(raw);
	
	std::cout << CYAN << " === Ptr struct === " << RESET << std::endl;
	std::cout	<< CYAN << "ptr->str: " << ptr->str << std::endl \
				<< "ptr->i: " << ptr->i << std::endl \
				<< "ptr->c: " << ptr->c << RESET << std::endl;

	return 0;
}
