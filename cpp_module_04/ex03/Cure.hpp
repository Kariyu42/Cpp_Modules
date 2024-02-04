/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:40:57 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/04 11:50:10 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

/*
* Cure is a class that inherits from AMateria.
* It has 2 methods: clone and use.
*/

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &copy);
		Cure	&operator=(Cure const &other);
		~Cure();

		AMateria	*clone( void ) const;
		void		use(ICharacter &target);
};

#endif
