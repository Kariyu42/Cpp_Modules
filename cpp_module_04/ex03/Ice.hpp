/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:31:37 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/04 11:46:16 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

/*
* Ice is a class that inherits from AMateria.
* It has 2 methods: clone and use.
*/

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &copy);
		Ice	&operator=(Ice const &other);
		~Ice();

		//* clone returns a new Ice object.
		AMateria	*clone( void ) const;
		//* use prints "* shoots an ice bolt at <target.getName()>".
		void		use(ICharacter &target);
};

#endif
