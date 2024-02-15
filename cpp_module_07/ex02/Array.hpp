/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:24:36 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/15 17:42:25 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include <cstdlib>

# define ARRAY_LEN 10

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

template <typename T>
class Array
{
	public:
		Array() : _array(NULL), _size(0) {
			return ;
		}
		Array(unsigned int n) : _array(new T[n]), _size(n) {
			return ;
		}
		Array(Array &a) : _array(new T[a.size()]), _size(a.size()) {
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = a[i];
			}
		}
		~Array() {
			if (_array)
				delete [] _array;
		}

		Array	&operator=(Array &a) {
			if (_array)
				delete [] _array;
			_array = new T[a.size()];
			_size = a.size();
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = a[i];
			}
			return *this;
		}

		T		&operator[](unsigned int i) {
			if (i >= this->_size) {
				throw std::exception();
			}
			return this->_array[i];
		}

		unsigned int	size() const {
			return this->_size;
		}

	private:
		T				*_array;
		unsigned int	_size;

};

#endif
