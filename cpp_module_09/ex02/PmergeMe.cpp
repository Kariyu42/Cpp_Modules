/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/24 15:37:28 by kquetat-         ###   ########.fr       */
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

void	PmergeMe::_sortPairs(std::vector<std::vector<int> > &pairs) {

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

void	PmergeMe::throwValues(std::vector<std::vector<int> > &pairs, std::vector<int> &container) {
	std::vector<std::vector<int> >::iterator	it = pairs.begin();
	std::vector<std::vector<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		container.push_back((*it).back());
		(*it).pop_back();
	}
	return ;
}

std::vector<int>	PmergeMe::initSequence(size_t size) {
	std::vector<int>	jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	for (size_t i = 2; i < size; i++) {
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
	}
	return jacobsthal;
}

void	showContainer(std::vector<std::vector<int> > &pairs) {
	std::vector<std::vector<int> >::iterator	it = pairs.begin();
	std::vector<std::vector<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		std::cout << CYAN << "[" << (*it).front() << ", " << (*it).back() << "] " RESET;
	}
	std::cout << std::endl;
	return ;
}

double	PmergeMe::_vectorSort(std::vector<int> &container) {
	struct timeval	start, end;
	int				straggler = 0;

	gettimeofday(&start, NULL);

	if (container.size() % 2 != 0) {
		straggler = container.back();
		container.pop_back();
	}
	_displayContainer(container);
	std::vector<std::vector<int> >	pairs = this->createPairs(container);
	std::cout << "Pairs before: " << std::endl;
	showContainer(pairs);
	this->_sortPairs(pairs);
	std::cout << "Pairs after: " << std::endl;
	showContainer(pairs);

	std::vector<int>	resSequence;
	std::vector<int>	smallSorted;
	this->throwValues(pairs, resSequence);
	std::cout << "resSequence: " << std::endl;
	_displayContainer(resSequence);
	this->throwValues(pairs, smallSorted);
	std::cout << "smallSorted: " << std::endl;
	_displayContainer(smallSorted);

	resSequence.insert(resSequence.begin(), smallSorted.front());
	smallSorted.erase(smallSorted.begin());
	std::vector<int>	jacobsthal = initSequence(container.size());
	std::cout << "jacobsthal: " << std::endl;
	_displayContainer(jacobsthal);

	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		if (jacobsthal[i] < static_cast<int>(smallSorted.size())) {
			int	index = jacobsthal[i];
			int	valueToInsert = smallSorted[index];
			std::vector<int>::iterator pos = std::lower_bound(resSequence.begin(), resSequence.end(), valueToInsert);
			resSequence.insert(pos, valueToInsert);
			std::cout << "smallSorted in for loop: " << std::endl;
			_displayContainer(smallSorted);
			std::cout << "resSequence in for loop: " << std::endl;
			_displayContainer(resSequence);
		}
	}
	if (straggler) {
		// use lower_bound to find the position of straggler in resSequence
		size_t	pos = std::lower_bound(resSequence.begin(), resSequence.end(), straggler) - resSequence.begin();
		resSequence.insert(resSequence.begin() + pos, straggler);
	}

	//* Copy resSequence to container
	container = resSequence;

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
	// this->_timeListSort = _listSort(this->_listContainer);

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
