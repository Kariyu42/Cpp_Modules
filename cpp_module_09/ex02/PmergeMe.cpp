/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/20 20:49:00 by kquetat-         ###   ########.fr       */
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
	//* Displaye one of the containers *//
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

double	PmergeMe::_vectorSort(std::vector<int> &container) {
	struct timeval	start, end;
	gettimeofday(&start, NULL);
	//* determine if container length is odd or even *//
	//* if it's odd, stock the last element in a variable and pop it *//
	if (container.size() % 2 != 0) {
		int	last = container.back();
		container.pop_back();
	}
	//* sort the pair of elements bitwise that are next to each other *//
	for (size_t i = 0; i < container.size(); i += 2) {
		if (container[i] > container[i + 1]) {
			std::swap(container[i], container[i + 1]);
		}
	}
	//* sort the pair sequence by its greater value *//
	for (size_t i = 2; i < container.size(); i += 4) {
		while (i < container.size() && container[i] < container[i + 2]) {
			std::swap(container[i], container[i + 2]);
			std::swap(container[i + 1], container[i + 3]);
			i += 2;
		}
	}
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &pmergeMe) {
	_vectorContainer = pmergeMe._vectorContainer;
	_listContainer = pmergeMe._listContainer;
	_timeVectorSort = pmergeMe._timeVectorSort;
	_timeListSort = pmergeMe._timeListSort;
	return *this;
}
