/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:55:03 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/18 18:39:08 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		
		void	announce( void ) const;
	private:
		std::string	_name;
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif
