/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:13:03 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 13:15:58 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB();

		void	attack( void ) const;
		void	setWeapon(Weapon& weapon);
	private:
		std::string	_name;
		Weapon	*_myWeapon;
};

#endif
