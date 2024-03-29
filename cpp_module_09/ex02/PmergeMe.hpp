/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:34:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/29 16:22:55 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iomanip>
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <exception>
# include <algorithm>
# include <sys/time.h>

//* Color codes *//
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"

class PmergeMe
{
	public:
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &pmergeMe);
		~PmergeMe( void );
		PmergeMe	&operator=(PmergeMe const &pmergeMe);

		//* Own implementation of exceptions *//
		class	InvalidArgument : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class	ArgumentSorted : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		static int	jacobsthal(int n);
	private:
		PmergeMe( void );

		//* ===== Vector Utils ===== *//
		std::vector<int>				_vectorContainer;
		double							_timeVectorSort;
		double							_vectorSort(std::vector<int> &container);
		std::vector<std::vector<int> >	_createVPairs(std::vector<int> &container);
		void							_sortVPairs(std::vector<std::vector<int> > &pairs);
		void							_throwVecValues(std::vector<std::vector<int> > &pairs, std::vector<int> &container);

		//* ===== Deque Utils ===== *//
		std::deque<int>					_dequeContainer;
		double							_timeDequeSort;
		double							_dequeSort(std::deque<int> &container);
		std::deque<std::deque<int> >	_createDPairs(std::deque<int> &container);
		void							_sortDPairs(std::deque<std::deque<int> > &pairs);
		void							_throwDeqValues(std::deque<std::deque<int> > &pairs, std::deque<int> &container);

		//* ===== Basic Utils ===== *//
		bool							_checkArgs(int ac, char **av);
		int								_strToInt(std::string str);
		bool							_dataSorted(int ac, char **av);

		//* ===== Display Utils ===== *//
		template <typename T>
		void	_displayContainer(T &container) {
			typename T::iterator	it = container.begin();
			typename T::iterator	ite = container.end();

			for (; it != ite; it++) {
				std::cout << CYAN << *it << " " RESET;
			}

			return ;
		}

		template <typename T>
		void	_displayPairs(T &container) {
			typename T::iterator	it = container.begin();
			typename T::iterator	ite = container.end();

			std::cout << "Pairs: " << std::endl;
			std::cout << "{ ";
			for (; it != ite; it++) {
				std::cout << "[ ";
				_displayContainer(*it);
				std::cout << "]";
			}
			std::cout << " }" << std::endl;
			return ;
		}

		template <typename T>
		void _displayAtNotSorted(T &container, size_t index) {
			typename T::iterator	it = container.begin();
			typename T::iterator	ite = container.end();

			for (size_t i = 0; it != ite; it++, i++) {
				std::cout << (i == index ? RED BOLD : CYAN) << *it << " " RESET;
			}

			return ;
		}
};

std::vector<int>		initVecSequence(size_t size);
std::deque<int>			initDeqSequence(size_t size);

#endif
