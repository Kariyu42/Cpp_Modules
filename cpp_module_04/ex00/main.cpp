/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:46:38 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 21:25:20 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main( void )
{
	{
		/* --- subject tests --- */
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		/* --- own tests --- */
		std::cout << std::endl;
		std::cout << "----- own tests -----" << std::endl;
		std::cout << std::endl;
		// Test with a Dog
		const Animal* dog = new Dog();
		std::cout << "type: " << dog->getType() << " " << std::endl;
		dog->makeSound();
		delete dog;

		// Test with a Cat
		const Animal* cat = new Cat();
		std::cout << "type: " << cat->getType() << " " << std::endl;
		cat->makeSound();
		delete cat;

		// Test with just Animal
		const Animal* animal = new Animal();
		std::cout << "type: " << animal->getType() << " " << std::endl;
		animal->makeSound();
		delete animal;
	}
	{
		/* --- test with wrong Animal --- */
		std::cout << std::endl;
		std::cout << "----- test with wrong Animal -----" << std::endl;
		std::cout << std::endl;

		const WrongAnimal* wrongAnimal = new WrongAnimal();
		std::cout << "type: " << wrongAnimal->getType() << " " << std::endl;
		wrongAnimal->makeSound();
		delete wrongAnimal;

		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << "type: " << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		delete wrongCat;
	}
	return 0;
}
