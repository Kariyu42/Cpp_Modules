/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:26:45 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/19 13:07:35 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	public:
		Weapon(std::string weapon);
		~Weapon();

		std::string	const &getType( void ) const;
		void		setType(std::string newType);
	private:
		std::string	type;
};

#endif
