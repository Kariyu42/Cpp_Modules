/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:52:44 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/15 16:10:50 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

# define MAX_LEN 5

//* Implement a function that iterates through an array and applies a function to each element.

template <typename T>
void	iter(T *array, size_t length, void (*f)(T const &))
{
	std::cout	<< BLUE << "The array contains " << length \
				<< " elements." << RESET << std::endl;
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif
