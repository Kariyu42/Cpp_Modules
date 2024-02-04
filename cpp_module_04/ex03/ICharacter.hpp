/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:27:16 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/04 11:51:52 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

/*
* ICharacter is an interface that will be implemented by the Character class.
* An __interface__ is a class that contains only pure virtual functions.
* A pure virtual function is a function that has no body and is declared with the "= 0" syntax.
* The ICharacter class has 4 pure virtual functions:
* - getName: returns the name of the character
* - equip: equip a materia to the character
* - unequip: unequip a materia from the character
* - use: use a materia from the character
*/

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const	&getName( void ) const = 0;
		virtual void				equip(AMateria *m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &target) = 0;
};

#endif
