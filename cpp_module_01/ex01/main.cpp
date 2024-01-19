/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:26:48 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/18 19:56:31 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	int			nbr = 4;
	std::string	name = "Chuck Bass";
	Zombie	*horde = zombieHorde(nbr, name);

	for (int i = 0; i < nbr; i++) {
		horde[i].announce();
	}
	
	delete [] horde;
	return 0;
}