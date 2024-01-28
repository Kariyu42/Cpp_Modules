/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/28 14:20:17 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	Opponent("Opponent");
	ClapTrap	noName;

	Opponent.setAttackDamage(5);
	noName.setAttackDamage(2);
	for (int i = 0; i < 5; i++) {
		Opponent.attack(noName.getName());
		noName.takeDamage(Opponent.getAttackDamage());
		noName.beRepaired(1);
		noName.checkStatus();
	}
	return 0;
}
