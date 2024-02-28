/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/28 12:13:20 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

char const	*PmergeMe::InvalidArgument::what() const throw() {
	return "Throwing an exception: Invalid argument.";
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

std::vector<std::vector<int> >	PmergeMe::_createVPairs(std::vector<int> &container) {
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

void	PmergeMe::_sortVPairs(std::vector<std::vector<int> > &pairs) {

	std::vector<std::vector<int> >::iterator	it = pairs.begin();
	std::vector<std::vector<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		if ((*it).front() > (*it).back()) {
			std::swap((*it).front(), (*it).back());
		}
	}

	it = pairs.begin();

	for (; it != ite; it++) {
		std::vector<std::vector<int> >::iterator	it2 = it + 1;
		std::vector<std::vector<int> >::iterator	ite2 = pairs.end();
		for (; it2 != ite2; it2++) {
			if ((*it).back() > (*it2).back()) {
				std::swap(*it, *it2);
			}
		}
	}

	return ;
}

void	PmergeMe::_throwVecValues(std::vector<std::vector<int> > &pairs, std::vector<int> &container) {
	std::vector<std::vector<int> >::iterator	it = pairs.begin();
	std::vector<std::vector<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		container.push_back((*it).back());
		(*it).pop_back();
	}

	return ;
}

int		PmergeMe::jacobsthal(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int>	PmergeMe::initSequence(size_t size) {
	int					jacobIndex = 3;
	std::vector<int>	jacobsthalSequence;

	while (jacobsthal(jacobIndex) <= static_cast<int>(size)) {
		jacobsthalSequence.push_back(jacobsthal(jacobIndex));
		jacobIndex++;
	}

	return jacobsthalSequence;
}

double	PmergeMe::_vectorSort(std::vector<int> &container) {
	struct timeval	start, end;
	int				straggler = 0;

	gettimeofday(&start, NULL);

	if (container.size() % 2 != 0) {
		straggler = container.back();
		container.pop_back();
	}

	std::vector<std::vector<int> >	pairs = this->_createVPairs(container);
	this->_sortVPairs(pairs);

	std::vector<int>	resSequence;
	std::vector<int>	smallSorted;
	this->_throwVecValues(pairs, resSequence);
	this->_throwVecValues(pairs, smallSorted);

	resSequence.insert(resSequence.begin(), smallSorted.front());
	smallSorted.erase(smallSorted.begin());
	std::vector<int>	jacobsthal = initSequence(smallSorted.size());

	std::vector<int>					idxSequence;
	int									lastInsertedIdx = -1;
	std::vector<int>::iterator	itJacob = jacobsthal.begin();

	for (size_t idx = 0; idx < smallSorted.size(); idx++) {
		if (itJacob != jacobsthal.end() && *itJacob == static_cast<int>(idx)) {
			if (std::find(idxSequence.begin(), idxSequence.end(), idx) == idxSequence.end()) {
				std::vector<int>::iterator	it = std::lower_bound(resSequence.begin(), resSequence.end(), smallSorted[idx]);
				resSequence.insert(it, smallSorted[idx]);
				idxSequence.push_back(idx);
				lastInsertedIdx = idx;
				itJacob++;
			}
		}
		else {
			if (lastInsertedIdx != static_cast<int>(idx)) {
				std::vector<int>::iterator	it = std::lower_bound(resSequence.begin(), \
																	resSequence.end(), \
																	smallSorted[idx]);
				resSequence.insert(it, smallSorted[idx]);
				idxSequence.push_back(idx);
			}
		}
	}

	if (straggler) {
		size_t	pos = std::lower_bound(resSequence.begin(), \
										resSequence.end(), \
										straggler) - resSequence.begin();
		resSequence.insert(resSequence.begin() + pos, straggler);
	}

	container = resSequence;

	gettimeofday(&end, NULL);
	double	time = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
	return time;
}

//* =============== List Functions =============== *//

std::list<std::list<int> >	PmergeMe::_createLPairs(std::list<int> &container) {
	std::list<std::list<int> >	pairs;
	std::list<int>::iterator		it = container.begin();
	std::list<int>::iterator		ite = container.end();
	for (; it != ite; it++) {
		std::list<int>	pair;
		pair.push_back(*it);
		it++;
		pair.push_back(*it);
		pairs.push_back(pair);
	}

	return pairs;
}

void	PmergeMe::_sortLPairs(std::list<std::list<int> > &pairs) {
	std::list<std::list<int> >::iterator	it = pairs.begin();
	std::list<std::list<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		if ((*it).front() > (*it).back()) {
			std::swap((*it).front(), (*it).back());
		}
	}

	it = pairs.begin();
	bool	swapped;

	do {
		swapped = false;
		std::list<std::list<int> >::iterator	nextIt = it;
		++nextIt;
		while (nextIt != pairs.end()) {
			if ((*it).back() > (*nextIt).back()) {
				std::swap(*it, *nextIt);
				swapped = true;
			}
			++nextIt;
			++it;
		}
	} while (swapped);

	return ;
}

double	PmergeMe::_listSort(std::list<int> &container) {
	struct timeval	start, end;
	int				straggler = 0;

	gettimeofday(&start, NULL);

	//* use the same algorithm as for vectors *//
	if (container.size() % 2 != 0) {
		straggler = container.back();
		container.pop_back();
	}
	std::list<std::list<int> >	pairs = this->_createLPairs(container);
	this->_sortLPairs(pairs);

	
	gettimeofday(&end, NULL);
	double	time = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
	return time;
}

PmergeMe::PmergeMe() {return ;}

PmergeMe::PmergeMe(int ac, char **av) : _timeVectorSort(0), _timeListSort(0) {
	if (checkArgs(ac, av) == false) {
		throw InvalidArgument();
	}

	for (int i = 1; i < ac; i++) {
		this->_vectorContainer.push_back(_strToInt(av[i]));
		// this->_listContainer.push_back(_strToInt(av[i]));
	}

	std::cout	<< YELLOW "Before: " RESET;
	_displayContainer(this->_vectorContainer);

	this->_timeVectorSort = _vectorSort(this->_vectorContainer);
	this->_timeListSort = _listSort(this->_listContainer);

	std::cout	<< YELLOW "After: " RESET;
	_displayContainer(this->_vectorContainer);
	// _displayContainer(this->_listContainer);
	
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &pmergeMe) : _vectorContainer(pmergeMe._vectorContainer), \
												_timeVectorSort(pmergeMe._timeVectorSort), \
												_listContainer(pmergeMe._listContainer), \
												_timeListSort(pmergeMe._timeListSort) {
	return ;
}

PmergeMe::~PmergeMe() {return ;}

PmergeMe	&PmergeMe::operator=(PmergeMe const &pmergeMe) {
	_vectorContainer = pmergeMe._vectorContainer;
	_listContainer = pmergeMe._listContainer;
	_timeVectorSort = pmergeMe._timeVectorSort;
	_timeListSort = pmergeMe._timeListSort;
	return *this;
}
