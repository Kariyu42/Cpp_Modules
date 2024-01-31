/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:44:03 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 21:49:18 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

# define GREY "\033[38;2;128;128;128m"
# define RESET "\033[0m"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &other);
		~Cat();

		void	makeSound( void ) const;
	private:
		Brain *_brain;
};

#endif
