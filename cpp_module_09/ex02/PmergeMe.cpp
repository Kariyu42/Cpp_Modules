/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/21 13:31:48 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {return ;}

PmergeMe::PmergeMe(int ac, char **av) : _timeVectorSort(0), _timeListSort(0) {
	if (checkArgs(ac, av) == false) {
		throw InvalidArgument();
	}
	//* once the arguments are checked, we can fill the containers *//
	for (int i = 1; i < ac; i++) {
		this->_vectorContainer.push_back(_strToInt(av[i]));
		this->_listContainer.push_back(_strToInt(av[i]));
	}
	//* Display one of the containers *//
	std::cout	<< YELLOW "Before: " RESET;
	_displayContainer(this->_vectorContainer);
	//* sort the list container and the vector container using the Ford-Johnson Merge Sort algorithm *//
	this->_timeVectorSort = _vectorSort(this->_vectorContainer);
	this->_timeListSort = _listSort(this->_listContainer);
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &pmergeMe) : _vectorContainer(pmergeMe._vectorContainer), \
												_listContainer(pmergeMe._listContainer), \
												_timeVectorSort(pmergeMe._timeVectorSort), \
												_timeListSort(pmergeMe._timeListSort) {
	return ;
}

PmergeMe::~PmergeMe() {return ;}

const char	*PmergeMe::InvalidArgument::what() const throw() {
	return "Exception caught: Invalid argument.";
}

void	PmergeMe::_displayContainer(std::vector<int> container) {
	std::vector<int>::iterator	it = container.begin();
	std::vector<int>::iterator	ite = container.end();
	for (; it != ite; it++) {
		std::cout << CYAN << *it << " " RESET;
	}
	std::cout << std::endl;
	return ;
}

bool	PmergeMe::checkArgs(int ac, char **av) {
	std::string		arg;
	int				i = 1;
	while (i < ac) {
		arg = av[i];
		for (size_t j = 0; j < arg.length(); j++) {
			if (!std::isdigit(arg[j])) {
				return false;
			}
		}
		i++;
	}
	//* check if there is duplicates *//
	std::vector<int>	unique;
	for (int i = 1; i < ac; i++) {
		unique.push_back(_strToInt(av[i]));
	}
	std::sort(unique.begin(), unique.end());
	std::vector<int>::iterator	it = unique.begin();
	std::vector<int>::iterator	ite = unique.end();
	for (; it != ite; it++) {
		if (*it == *(it + 1)) {
			return false;
		}
	}
	return true;
}

int	PmergeMe::_strToInt(std::string str) {
	std::istringstream	ss(str);
	int					n;
	ss >> n;
	return n;
}

std::vector<std::vector<int> >	PmergeMe::createPairs(std::vector<int> &container) {
	std::vector<std::vector<int> >	pairs;
	std::vector<int>::iterator		it = container.begin();
	std::vector<int>::iterator		ite = container.end();
	for (; it != ite; it++) {
		std::vector<int>	pair;
		pair.push_back(*it);
		it++;
		pair.push_back(*it);
		pairs.push_back(pair);
	}
	return pairs;
}

bool	PmergeMe::ComparePairs::operator()(std::vector<int> &a, std::vector<int> &b) {
	//* compare the the highest value of each pair *//
	return a.back() < b.back(); // if a is smaller than b, return true
	//* std::sort will sort the pairs in ascending order *//
}

void	PmergeMe::sortPairs(std::vector<std::vector<int> > &pairs) {
	
	std::vector<std::vector<int> >::iterator	it = pairs.begin();
	std::vector<std::vector<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		std::vector<std::vector<int> >::iterator	it2 = it + 1;
		std::vector<std::vector<int> >::iterator	ite2 = pairs.end();
		for (; it2 != ite2; it2++) {
			if ((*it).back() > (*it2).back()) {
				std::swap(*it, *it2);
			}
		}
	}
}

double	PmergeMe::_vectorSort(std::vector<int> &container) {
	struct timeval	start, end;
	gettimeofday(&start, NULL);
	//* determine if container length is odd or even *//
	//* if it's odd, stock the last element in a variable and pop it *//
	if (container.size() % 2 != 0) {
		int	last = container.back();
		container.pop_back();
	}
	//* create pairs *//
	std::vector<std::vector<int> >	pairs = this->createPairs(container);
	//* sort each pair *//
	std::vector<std::vector<int> >::iterator	it = pairs.begin();
	std::vector<std::vector<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		if ((*it).front() > (*it).back()) {
			std::swap((*it).front(), (*it).back());
		}
	}
	//* sort the pair sequence by its greater value *//
	this->sortPairs(pairs);
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &pmergeMe) {
	_vectorContainer = pmergeMe._vectorContainer;
	_listContainer = pmergeMe._listContainer;
	_timeVectorSort = pmergeMe._timeVectorSort;
	_timeListSort = pmergeMe._timeListSort;
	return *this;
}
