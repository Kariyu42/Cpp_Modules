/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:31:03 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/31 21:34:36 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

class Brain
{
	public:
		Brain();
		Brain(Brain const &copy);
		Brain	&operator=(Brain const &other);
		~Brain();

		std::string	*getIdeas( void );
		void		setIdeas( std::string *ideas );

	private:
		std::string	_ideas[100];
};

#endif
