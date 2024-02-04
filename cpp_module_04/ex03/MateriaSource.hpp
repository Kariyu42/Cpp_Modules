/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:26:30 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/04 13:24:08 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

# define MAX_MATERIAS 4

/*
* MateriaSource is a class that will be used to learn and create new materia.
* It has 4 materias that can be learned and created.
* The materias are stored in an array of AMateria pointers.
* The MateriaSource class has 2 methods: learnMateria and createMateria
*/

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource	&operator=(MateriaSource const &other);
		~MateriaSource();

		void		learnMateria(AMateria *);
		AMateria	*createMateria(std::string const &type);

	private:
		AMateria	*_materias[MAX_MATERIAS];
};

#endif
