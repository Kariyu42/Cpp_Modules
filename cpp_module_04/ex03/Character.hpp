/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:55:07 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/06 14:26:16 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <new>
# include <cstdlib>
# include <iostream>
# include "ICharacter.hpp"

// Colours
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define ROSE "\033[0;35m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

// Maximal number of materias
# define MAX_MATERIAS 4

/*
* Character is the class that implements the ICharacter interface.
* It has 4 materias that can be equipped and used.
* The materias are stored in an array of AMateria pointers.
* The Character class has 4 methods: getName, equip, unequip and use.
*/

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string const &name);
		Character(Character const &copy);
		Character	&operator=(Character const &other);
		~Character();

		std::string const	&getName( void ) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		AMateria			**updateGroundMateria( int idx );
		void				showGroundMateria( void );
	private:
		std::string	_name;
		AMateria	*_materias[MAX_MATERIAS];
		AMateria	**_groundMateria; // To store the materias that are on the ground
		size_t		_countGroundMateria; // To store the number of materias on the ground
};

#endif
