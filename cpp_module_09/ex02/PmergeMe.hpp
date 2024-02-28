/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:34:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/28 16:36:51 by kquetat-         ###   ########.fr       */
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

		static int	jacobsthal(int n);
	private:
		PmergeMe( void );

		double	_timeVectorSort;
		std::vector<int>	_vectorContainer;
		double	_vectorSort(std::vector<int> &container);
		std::vector<std::vector<int> >	_createVPairs(std::vector<int> &container);
		void	_sortVPairs(std::vector<std::vector<int> > &pairs);
		void	_throwVecValues(std::vector<std::vector<int> > &pairs, std::vector<int> &container);

		double	_timeListSort;
		std::list<int>	_listContainer;
		double	_listSort(std::list<int> &container);
		std::list<std::list<int> >	_createLPairs(std::list<int> &container);
		void	_sortLPairs(std::list<std::list<int> > &pairs);
		void	_throwLstValues(std::list<std::list<int> > &pairs, std::list<int> &container);

		//* ===== Basic Utils ===== *//
		bool	_checkArgs(int ac, char **av);
		int		_strToInt(std::string str);
		void	_displayContainer(std::vector<int> container);

};

std::vector<int>		initVecSequence(size_t size);
std::list<int>			initLstSequence(size_t size);

#endif
