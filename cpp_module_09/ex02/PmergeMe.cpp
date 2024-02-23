/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/22 14:18:20 by kquetat-         ###   ########.fr       */
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

void	PmergeMe::throwValues(std::vector<std::vector<int> > &pairs, std::vector<int> &container) {
	std::vector<std::vector<int> >::iterator	it = pairs.begin();
	std::vector<std::vector<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		container.push_back((*it).back());
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

/*
* Pour réaliser les étapes 5 à 9 de l'algorithme Ford-Johnson pour créer une séquence S
* triée, vous devez d'abord séparer les valeurs les plus grandes (déjà triées) des paires
* dans un nouveau tableau S et les plus petites dans un tableau temporaire pend. Insérez
* ensuite la première valeur de pend au début de S, car elle est plus petite que le premier
* élément de S. Après, utilisez les nombres de Jacobsthal pour déterminer la séquence
* d'insertion optimale dans S, en tirant parti de l'efficacité du tri binaire dans le pire
* des cas. Enfin, si un "straggler" existe, insérez-le dans S en utilisant une recherche
* binaire pour trouver sa position correcte. Ce processus complexe vise à minimiser les
* comparaisons nécessaires pour trier l'ensemble des données.
*/

double	PmergeMe::_vectorSort(std::vector<int> &container) {
	struct timeval	start, end;
	gettimeofday(&start, NULL);
	if (container.size() % 2 != 0) {
		int	last = container.back();
		container.pop_back();
	}
	std::vector<std::vector<int> >	pairs = this->createPairs(container);

	std::vector<std::vector<int> >::iterator	it = pairs.begin();
	std::vector<std::vector<int> >::iterator	ite = pairs.end();
	for (; it != ite; it++) {
		if ((*it).front() > (*it).back()) {
			std::swap((*it).front(), (*it).back());
		}
	}
	this->sortPairs(pairs);
	std::vector<int>	bigSorted;
	std::vector<int>	smallSorted;
	this->throwValues(pairs, bigSorted);
	this->throwValues(pairs, smallSorted);
	bigSorted.insert(bigSorted.begin(), smallSorted.front());
	//* Jacobsthal numbers *//
	std::vector<int>	jacobsthal = initSequence(container.size());
	//* once we have our sequence, iterate through the smallSorted container and insert the values in the bigSorted container *//
	std::vector<int>::iterator	it2 = smallSorted.begin();
	while (it2 != smallSorted.end()) {
		//* if we have a valid jacobshtal number, insert it in the bigSorted container *//
		if (std::find(jacobsthal.begin(), jacobsthal.end(), *it2) != jacobsthal.end()) {
			bigSorted.push_back(*it2);
			smallSorted.erase(it2);
		}
		else {
			//*
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
