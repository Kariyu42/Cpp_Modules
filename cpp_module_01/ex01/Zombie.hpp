/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:55:03 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/18 19:52:45 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();

		void	setName(std::string& str);

		void	announce( void ) const;
	private:
		std::string	_name;
};

Zombie *zombieHorde( int N, std::string name );

#endif
