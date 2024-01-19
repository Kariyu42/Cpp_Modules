/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:26:48 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/18 18:50:13 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	/* ----- Zombie heap ----- */
	Zombie	*allocZombie = newZombie("Croquette");
	allocZombie->announce();

	/* ----- Zombie stack ----- */
	randomChump("Bernard");

	/* ----- Zombie destroyed heap ----- */
	delete allocZombie;
	return 0;
}