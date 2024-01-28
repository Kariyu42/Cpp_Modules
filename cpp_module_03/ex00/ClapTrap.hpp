/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:37:11 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/28 14:31:51 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class ClapTrap
{
	public:
		// Canonical form*
		ClapTrap(); // Default constructor*
		ClapTrap(std::string name); // Parametric constructor
		ClapTrap(ClapTrap const &copy); // Copy constructor*
		~ClapTrap(); // Destructor*
		ClapTrap &operator=(ClapTrap const &other); // Assignation operator overload*

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName( void ) const;
		int			getHitPoints( void ) const;
		int			getEnergyPoints( void ) const;
		int			getAttackDamage( void ) const;
		void		checkStatus( void ) const;

		void		setAttackDamage(int amount);

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif
