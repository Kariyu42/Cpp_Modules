/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:11:02 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/17 15:15:28 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <cstdlib>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

# define V_LENGTH 5
# define V2_LENGTH 20

class Span
{
	public:
		Span( void );
		Span(unsigned int n);
		Span(Span const &copy);
		~Span( void );

		Span	&operator=(Span const &sp);

		void				addNumber(int n);
		void				addNNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int					shortestSpan( void );
		int					longestSpan( void );


		std::vector<int>	getVector( void ) const;

		class SpanFullException : public std::exception {
			virtual const char *what() const throw();
		};

		class SpanTooShortException : public std::exception {
			virtual const char *what() const throw();
		};

	private:
		unsigned int		_n;
		std::vector<int>	_v;

};

#endif
