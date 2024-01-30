/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/30 13:56:05 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	FragTrap	Kendrick("Kendrick");
	FragTrap	Drake("Drake");

	Kendrick.checkStatus();
	Drake.checkStatus();
	Drake.highFivesGuys();
	for (int i = 0; i < 5; i++) {
		Kendrick.attack(Drake.getName());
		Drake.takeDamage(Kendrick.getAttackDamage());
		Drake.checkStatus();
		Kendrick.checkStatus();
	}
}
