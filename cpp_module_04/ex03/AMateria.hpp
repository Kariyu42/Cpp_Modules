/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:28:09 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/04 11:43:26 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <new>
# include <iostream>
# include <cstdlib>
# include "ICharacter.hpp"

class ICharacter;

/*
* AMateria is an abstract class that will be implemented by the Ice and Cure classes.
* An __abstract class__ is a class that contains at least one pure virtual function.
* It has:
* - 1 protected attribute: _type, a string that represents the type of materia.
* - 3 methods: getType, clone and use.
*/

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
		AMateria	&operator=(AMateria const &other);
		virtual ~AMateria();

		std::string const	&getType( void ) const;
		virtual AMateria	*clone( void ) const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string	_type;
};

#endif
