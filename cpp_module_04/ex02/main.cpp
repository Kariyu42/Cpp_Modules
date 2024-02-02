/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:46:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/02 12:24:37 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

void	initAnimals(Animal *animals[], int nbr) {
	for (int i = 0; i < nbr; i++) {
		if (i % 2 == 0) {
			animals[i] = new (std::nothrow) Dog();
		} else {
			animals[i] = new (std::nothrow) Cat();
		}
		if (!animals[i])
		{
			std::cerr	<< RED \
						<< "Error: Memory allocation failed." \
						<< RESET << std::endl;
			exit(1);
		}
	}
	return ;
}

int main( void )
{
	// subject main
	std::cout << GREEN << " --- Subject main --- " << RESET << std::endl;
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << std::endl;
	delete j;
	delete i;

	std::cout << std::endl;

	// my main
	std::cout << CYAN << " --- My main --- " << RESET << std::endl;
	const int		nbr = 4;
	Animal	*animals[nbr];

	initAnimals(animals, nbr);
	for (int i = 0; i < nbr; i++) {
		animals[i]->makeSound();
		animals[i]->printIdeas();
		delete animals[i];
		animals[i] = NULL;
	}
	// Animal testAnimal; // error because Animal is abstract
	return 0;
}
