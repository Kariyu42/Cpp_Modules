/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:07:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/30 13:50:05 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

#define B_MAGENTA "\033[1;35m"
#define B_CYAN "\033[1;36m"
#define B_YELLOW "\033[1;33m"
#define B_RED "\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_BLUE "\033[1;34m"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &copy);
		~FragTrap();
		FragTrap	&operator=(FragTrap const &other);

		void		highFivesGuys( void );
		void		checkStatus( void );
};

#endif
