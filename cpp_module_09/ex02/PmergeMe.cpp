/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/29 16:33:13 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//* Exception implementation *//
char const	*PmergeMe::InvalidArgument::what() const throw() {
	return "Throwing an exception: Invalid argument.";
}

char const	*PmergeMe::ArgumentSorted::what() const throw() {
	return "Throwing an exception: Argument is already sorted.";
}

//* =============== Utils =============== *//
bool	PmergeMe::_checkArgs(int ac, char **av) {
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

	std::vector<int>	unique;
	for (int i = 1; i < ac; i++) {
		unique.push_back(_strToInt(av[i]));
	}

	std::sort(unique.begin(), unique.end());
	std::vector<int>::iterator	it = unique.begin();
	std::vector<int>::iterator	ite = unique.end();
	for (; it != ite - 1; it++) {
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

bool	PmergeMe::_dataSorted(int ac, char **av) {
	int	i = 1;
	while (i < ac - 1) {
		if (_strToInt(av[i]) > _strToInt(av[i + 1])) {
			return false;
		}
		i++;
	}
	return true;
}

int		PmergeMe::jacobsthal(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

//* =============== Vector Functions =============== *//
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

std::vector<int>	initVecSequence(size_t size) {
	int					jacobIndex = 3;
	std::vector<int>	jacobsthalSequence;

	while (PmergeMe::jacobsthal(jacobIndex) <= static_cast<int>(size)) {
		jacobsthalSequence.push_back(PmergeMe::jacobsthal(jacobIndex));
		jacobIndex++;
	}

	return jacobsthalSequence;
}

double	PmergeMe::_vectorSort(std::vector<int> &container) {
	struct timeval	start, end;
	int				straggler = -1;

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
	std::vector<int>	jacobsthal = initVecSequence(smallSorted.size());

	std::vector<int>					idxSequence;
	int									lastInsertedIdx = -1;
	std::vector<int>::iterator	itJacob = jacobsthal.begin();

	for (size_t idx = 0; idx < smallSorted.size(); idx++) {
		if (itJacob != jacobsthal.end() && *itJacob == static_cast<int>(idx)) {
			if (std::find(idxSequence.begin(), idxSequence.end(), idx) == idxSequence.end()) {
				std::vector<int>::iterator	it = std::lower_bound(resSequence.begin(), \
																	resSequence.end(), \
																	smallSorted[idx]);
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

	if (straggler != -1) {
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

//* =============== Deque Functions =============== *//

std::deque<std::deque<int> >	PmergeMe::_createDPairs(std::deque<int> &container) {
	std::deque<std::deque<int> >	pairs;
	std::deque<int>::iterator		it = container.begin();
	std::deque<int>::iterator		ite = container.end();
	for (; it != ite; it++) {
		std::deque<int>	pair;
		pair.push_back(*it);
		it++;
		pair.push_back(*it);
		pairs.push_back(pair);
	}

	return pairs;
}

void	PmergeMe::_sortDPairs(std::deque<std::deque<int> > &pairs) {
	std::deque<std::deque<int> >::iterator	it = pairs.begin();
	std::deque<std::deque<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		if ((*it).front() > (*it).back()) {
			std::swap((*it).front(), (*it).back());
		}
	}

	bool	swapped;

	do {
		swapped = false;
		it = pairs.begin();
		while (it != pairs.end() && (it + 1) != pairs.end()) {
			std::deque<std::deque<int> >::iterator	nextIt = it + 1;
			if ((*it).back() > (*nextIt).back()) {
				std::swap(*it, *nextIt);
				swapped = true;
			}
			it++;
		}
	} while (swapped);

	return ;
}

void	PmergeMe::_throwDeqValues(std::deque<std::deque<int> > &pairs, std::deque<int> &container) {
	std::deque<std::deque<int> >::iterator it = pairs.begin();
	std::deque<std::deque<int> >::iterator ite = pairs.end();

	for (; it != ite; it++) {
		container.push_back((*it).back());
		(*it).pop_back();
	}

	return ;
}

std::deque<int>	initDeqSequence(size_t size) {
	int	jacobIndex = 3;
	std::deque<int>	jacobsthaleSequence;

	while (PmergeMe::jacobsthal(jacobIndex) <= static_cast<int>(size)) {
		jacobsthaleSequence.push_back(PmergeMe::jacobsthal(jacobIndex));
		jacobIndex++;
	}

	return jacobsthaleSequence;
}

double	PmergeMe::_dequeSort(std::deque<int> &container) {
	struct timeval	start, end;
	int				straggler = -1;

	gettimeofday(&start, NULL);

	if (container.size() % 2 != 0) {
		straggler = container.back();
		container.pop_back();
	}
	std::deque<std::deque<int> >	pairs = this->_createDPairs(container);
	this->_sortDPairs(pairs);

	std::deque<int>	resSequence;
	std::deque<int>	smallSorted;
	this->_throwDeqValues(pairs, resSequence);
	this->_throwDeqValues(pairs, smallSorted);

	resSequence.insert(resSequence.begin(), smallSorted.front());
	smallSorted.erase(smallSorted.begin());
	std::deque<int>	jacobsthal = initDeqSequence(smallSorted.size());

	std::deque<int>	idxSequence;
	int	lastInsertedIndex = -1;
	std::deque<int>::iterator	itJacob = jacobsthal.begin();

	for (size_t idx = 0; idx < smallSorted.size(); idx++) {
		if (itJacob != jacobsthal.end() && *itJacob == static_cast<int>(idx)) {
			if (std::find(idxSequence.begin(), idxSequence.end(), idx) == idxSequence.end()) {
				std::deque<int>::iterator	it = std::lower_bound(resSequence.begin(), \
																	resSequence.end(), \
																	smallSorted[idx]);
				resSequence.insert(it, smallSorted[idx]);
				idxSequence.push_back(idx);
				lastInsertedIndex = idx;
				itJacob++;
			}
		}
		else {
			if (lastInsertedIndex != static_cast<int>(idx)) {
				std::deque<int>::iterator	it = std::lower_bound(resSequence.begin(), \
																	resSequence.end(), \
																	smallSorted[idx]);
				resSequence.insert(it, smallSorted[idx]);
				idxSequence.push_back(idx);
			}
		}
	}

	if (straggler != -1) {
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

//* =============== Canonical Form =============== *//
PmergeMe::PmergeMe() {return ;}

PmergeMe::PmergeMe(int ac, char **av) : _timeVectorSort(0), _timeDequeSort(0) {
	if (this->_checkArgs(ac, av) == false) {
		throw InvalidArgument();
	}
	else if (this->_dataSorted(ac, av) == true) {
		throw ArgumentSorted();
	}

	for (int i = 1; i < ac; i++) {
		this->_vectorContainer.push_back(_strToInt(av[i]));
		this->_dequeContainer.push_back(_strToInt(av[i]));
	}

	std::cout	<< YELLOW "Before: " RESET;
	_displayContainer(this->_vectorContainer);
	std::cout << std::endl;

	this->_timeVectorSort = _vectorSort(this->_vectorContainer);
	this->_timeDequeSort = _dequeSort(this->_dequeContainer);

	std::cout	<< YELLOW "After:  " RESET;
	_displayContainer(this->_vectorContainer);
	std::cout << std::endl;

	//* print the time to process for both containers in micro seconds *//
	std::cout	<< GREEN "Time to process a range of " BLUE << _vectorContainer.size() << GREEN \
				<< " elements with " MAGENTA "std::vector : " GREEN BOLD << std::setprecision(5) \
				<< _timeVectorSort << " us" << RESET << std::endl;

	std::cout	<< GREEN "Time to process a range of " BLUE << _dequeContainer.size() << GREEN \
				<< " elements with " MAGENTA "std::deque : " GREEN BOLD << std::setprecision(5) \
				<< _timeDequeSort << " us" << RESET << std::endl;

	std::vector<int>::iterator	it = this->_vectorContainer.begin();
	std::vector<int>::iterator	ite = this->_vectorContainer.end();
	std::deque<int>::iterator	it2 = this->_dequeContainer.begin();
	std::deque<int>::iterator	ite2 = this->_dequeContainer.end();

	//* check duplicates in vector *//
	for (; it != ite; it++) {
		if (std::find(it + 1, ite, *it) != ite) {
			std::cout << RED "Error: Duplicates in vector container." RESET << std::endl;
			throw InvalidArgument();
		}
	}

	//* check duplicates in deque *//
	for (; it2 != ite2; it2++) {
		if (std::find(it2 + 1, ite2, *it2) != ite2) {
			std::cout << RED "Error: Duplicates in deque container." RESET << std::endl;
			throw InvalidArgument();
		}
	}

	it = this->_vectorContainer.begin();
	it2 = this->_dequeContainer.begin();
	for (; it != ite; it++) {
		if (it + 1 != ite && *it > *(it + 1)) {
			std::cout << RED "Error: Vector container is not sorted." RESET << std::endl;
			throw InvalidArgument();
		}
	}
	for (; it2 != ite2; it2++) {
		if (it2 + 1 != ite2 && *it2 > *(it2 + 1)) {
			std::cout << RED "Error: Deque container is not sorted." RESET << std::endl;
			throw InvalidArgument();
		}
	}

	return ;
}

PmergeMe::PmergeMe(PmergeMe const &pmergeMe) : _vectorContainer(pmergeMe._vectorContainer), \
												_timeVectorSort(pmergeMe._timeVectorSort), \
												_dequeContainer(pmergeMe._dequeContainer), \
												_timeDequeSort(pmergeMe._timeDequeSort) {
	return ;
}

PmergeMe::~PmergeMe() {return ;}

PmergeMe	&PmergeMe::operator=(PmergeMe const &pmergeMe) {
	_vectorContainer = pmergeMe._vectorContainer;
	_dequeContainer = pmergeMe._dequeContainer;
	_timeVectorSort = pmergeMe._timeVectorSort;
	_timeDequeSort = pmergeMe._timeDequeSort;
	return *this;
}
