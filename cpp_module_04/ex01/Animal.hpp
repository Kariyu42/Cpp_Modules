/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:18:13 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/02 11:03:51 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <new>

# define RED "\033[0;31m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &copy);
		virtual ~Animal();
		Animal	&operator=(Animal const &other);

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;

		virtual void	printIdeas( void ) const = 0;
	protected:
		std::string	_type;
};

#endif
