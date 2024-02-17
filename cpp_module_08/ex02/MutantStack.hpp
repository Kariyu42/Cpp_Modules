/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:23:01 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/17 20:11:33 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

template <typename T> class MutantStack : public std::stack<T> {

	public:
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		MutantStack( void ) : std::stack<T>() {return ;}
		MutantStack(MutantStack const &src) : std::stack<T>(src) {return ;}
		~MutantStack( void ) {return ;}
		MutantStack	&operator=(MutantStack const &rhs) {
			if (this != &rhs) {
				this->c = rhs.c;
			}
			return *this;
		}

		//* Iterators
		iterator begin( void ) {return this->c.begin();}
		iterator end( void ) {return this->c.end();}
		const_iterator begin( void ) const {return this->c.begin();}
		const_iterator end( void ) const {return this->c.end();}
		reverse_iterator rbegin( void ) {return this->c.rbegin();}
		reverse_iterator rend( void ) {return this->c.rend();}
		const_reverse_iterator rbegin( void ) const {return this->c.rbegin();}
		const_reverse_iterator rend( void ) const {return this->c.rend();}

};

#endif
