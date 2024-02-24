/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/24 17:59:18 by kquetat-         ###   ########.fr       */
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
		std::cout << "Straggler holding: " << GREEN "[" << straggler << "]" RESET << std::endl;
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
	std::cout << "smallSorted after insert: " << std::endl;
	_displayContainer(smallSorted);
	std::cout << "resSequence after insert: " << std::endl;
	_displayContainer(resSequence);
	std::vector<int>	jacobsthal = initSequence(smallSorted.size());

	std::cout << BLUE "===== ENTERING FOR LOOP =====" << RESET << std::endl;
	std::cout << "jacobsthal: " << std::endl;
	_displayContainer(jacobsthal);
	size_t size = jacobsthal.size();
	std::cout << "size jaco = " << size << std::endl;
	
	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		if (jacobsthal[i] <= static_cast<int>(smallSorted.size())) {
			std::cout << "i = " << i << std::endl;
			int	index = jacobsthal[i];
			//* need to handle the case where we encounter at index of jacobsthal two 1
			//* e.g => jacobsthal = {0, 1, 1, 3, 5, 9, 17, 31, 57, 105, 193, 355, 653, 1201, 2209, 4063, 7473, 13745, 25281, 46561, 85937, 158817, 293545, 540897, 997537, 1838741, 3392821, 6259741, 11552003, 21300629, 39226497, 72277377, 133261153, 245122753, 451861833, 832635457, 1536796801, 2839725265, 5237523377, 9668440203, 17840596177, 32895996545, 60635500121, 111687796799, 205930635321, 379891791841, 699345613057, 1288020210177, 2372515049745, 4375099216777, 8068443231903, 14874205271457, 27442383003393, 50501915861057, 93080415718081, 171457098692417, 316729578526273, 583248240622881, 1073734579286017, 1977308325976833, 3644230590339329, 6716539779776193, 12379400392853889, 22802510499212033, 42047528254943873, 77564142197338241, 142882242814746337, 263747951750360641, 486675264292965377, 897697708241906817, 1655617327040999937, 3057227021950580225, 5632544161009530113, 10385522901205533313, 19152845158865828481, 35345263893403836033, 65173993025112145537, 120261084602236058625, 221424845759342384897, 408855843832398455553, 753778764945832576001, 138953697008169158337
			if (i > 0 && jacobsthal[i] == jacobsthal[i - 1]) {
				index++;
			}
			std::cout << YELLOW "index = " << index << RESET << std::endl;
			int	valueToInsert = smallSorted[index];
			std::cout << RED "valueToInsert = " << valueToInsert << RESET << std::endl;
			std::vector<int>::iterator pos = std::lower_bound(resSequence.begin(), resSequence.end(), valueToInsert);
			//* this function will return an iterator pointing to the first element in the range [first, last) which does not compare less than valueToInsert
			//* and the insert will insert valueToInsert before the element pointed by pos
			//* e.g => resSequence = {1, 3, 5, 7, 9}, valueToInsert = 4, pos = 5
			resSequence.insert(pos, valueToInsert);
			//* rm value from smallSorted
			// smallSorted.erase(smallSorted.begin() + index);
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
