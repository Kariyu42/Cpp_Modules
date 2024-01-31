/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:35:24 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 17:37:02 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

# define BROWN "\033[38;2;139;69;19m"
# define RESET "\033[0m"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &other);
		~Dog();

		void	makeSound( void ) const;
};

#endif
