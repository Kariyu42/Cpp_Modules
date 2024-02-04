/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:02:18 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/04 18:02:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void	subjectMain( void )
{
	// Main from the subject
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	myMain( void )
{
	// My main
	IMateriaSource *bag = new MateriaSource();
	bag->learnMateria(new Ice());
	bag->learnMateria(new Cure());
	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = bag->createMateria("ice");
	me->equip(tmp);
	tmp = bag->createMateria("cure");
	me->equip(tmp);
	tmp = bag->createMateria("cure");
	me->equip(tmp);
	tmp = bag->createMateria("ice");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");

	std::cout << std::endl;
	std::cout	<< YELLOW \
				<< " === Using the 4 materias === " \
				<< RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << RESET;
	// idx 4 error => only 4 materias
	me->use(4, *bob);

	me->equip(bag->createMateria("ice"));

	std::cout << std::endl;
	std::cout	<< YELLOW \
				<< " === Unequip the 1st materia and use it === " \
				<< RESET << std::endl;
	std::cout << std::endl;
	me->unequip(0);
	me->use(0, *bob);
	me->unequip(0); // prints an error message since unequipped just before
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	std::cout << std::endl;
	std::cout	<< YELLOW \
				<< " === Delete the characters and the bag === " \
				<< RESET << std::endl;
	std::cout << std::endl;
	delete bob;
	delete me;
	delete bag;
}

int main( void )
{
	std::cout	<< GREEN \
				<< " ================== Subject main ================== " \
				<< RESET << std::endl;
	std::cout << std::endl;
	subjectMain();

	// My main
	std::cout	<< ROSE \
				<< " ================== My main ================== " \
				<< RESET << std::endl;
	std::cout << std::endl;
	myMain();
	return 0;
}
