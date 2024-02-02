/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:31:03 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/02 10:50:59 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <cstdlib>
# include <new>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define ROSE "\033[0;35m"
# define RESET "\033[0m"

# define NBR_IDEAS 100

class Brain
{
	public:
		Brain();
		Brain(std::string animalType);
		Brain(Brain const &copy);
		Brain	&operator=(Brain const &other);
		~Brain();

		std::string	*getIdeas( void );
		void		setIdeas( std::string ideas );

		void		putIdeas( void ) const;
	private:
		std::string	_ideas[NBR_IDEAS];
};

#endif
