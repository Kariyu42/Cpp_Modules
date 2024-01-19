/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:55:11 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/18 19:33:10 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name ) {
	Zombie	*allocZombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		allocZombies[i].setName(name);
	}
	return allocZombies;
}