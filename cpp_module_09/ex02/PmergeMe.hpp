/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:34:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/26 10:11:00 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
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
# define UNDERLINE	"\033[4m"
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

	private:
		PmergeMe( void );

		std::vector<int>		_vectorContainer;
		double					_timeVectorSort;
		double					_vectorSort(std::vector<int> &container);

		std::list<int>			_listContainer;
		double					_timeListSort;
		double					_listSort(std::list<int> &container);

		int						_strToInt(std::string str);
		void					_displayContainer(std::vector<int> container);

		bool					checkArgs(int ac, char **av);
		std::vector<std::vector<int> >		createPairs(std::vector<int> &container);
		void					_sortPairs(std::vector<std::vector<int> > &pairs);
		void					throwValues(std::vector<std::vector<int> > &pairs, std::vector<int> &container);
		std::vector<int>		initSequence(size_t size);
		int						jacobsthal(int n);
};

#endif
