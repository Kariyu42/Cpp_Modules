/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/27 19:09:38 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	Opponent("Opponent");
	ClapTrap	noName;

	for (int i = 0; i < 5; i++) {
		Opponent.attack(noName.getName());
		noName.takeDamage(2);
		Opponent.beRepaired(2);
	}
}
