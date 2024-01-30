/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/30 12:01:03 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	Opponent("Opponent");
	ScavTrap	noName = ScavTrap();

	noName.guardGate();
	for (int i = 0; i < 5; i++) {
		Opponent.attack(noName.getName());
		noName.takeDamage(Opponent.getAttackDamage());
		noName.checkNewStatus();
	}
	return 0;
}
