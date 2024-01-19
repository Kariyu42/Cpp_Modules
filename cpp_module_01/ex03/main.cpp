/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:26:05 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 13:30:05 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main( void )
{
	/* --- subject main --- */
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	/* --- other main --- */
	{
		Weapon	club = Weapon("Mjölnir");
		HumanA	thor("Thor", club);
		thor.attack();
		club.setType("Tennis racket");
		thor.attack();
	}
	{
		Weapon	club = Weapon("pancake");
		HumanB	jennifer("Jennifer");
		HumanB	vinicius("Vinicius");

		jennifer.setWeapon(club);
		jennifer.attack();
		
		vinicius.attack();
	}
	return 0;
}