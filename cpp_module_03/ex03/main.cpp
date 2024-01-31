/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 16:22:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap	Jack("Jack");
	FragTrap	Dave("Dave");

	Jack.whoAmI();
	Jack.attack("Dave");
	Dave.takeDamage(Jack.getAttackDamage());
	Jack.highFivesGuys();
	Jack.guardGate();
	Jack.beRepaired(10);
}
