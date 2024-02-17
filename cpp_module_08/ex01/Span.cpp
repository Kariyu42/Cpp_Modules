/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:34:13 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/17 15:10:37 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _n(0) {return ;}

Span::Span(unsigned int n) : _n(n) {return ;}

Span::Span(Span const &copy) : _n(copy._n), _v(copy._v) {
	*this = copy;
	return ;
}

Span::~Span( void ) {return ;}

Span	&Span::operator=(Span const &sp)
{
	this->_v.clear();
	this->_n = sp._n;
	this->_v = sp._v;
	return *this;
}

std::vector<int>	Span::getVector( void ) const {
	return this->_v;
}

const char	*Span::SpanFullException::what() const throw() {
	return "Span is full";
}

const char	*Span::SpanTooShortException::what() const throw() {
	return "Span is too short";
}

void	Span::addNumber(int n) {
	if (this->_v.size() < this->_n)
		this->_v.push_back(n);
	else
		throw Span::SpanFullException();
}

void	Span::addNNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_v.size() + std::distance(begin, end) <= this->_n)
		this->_v.insert(this->_v.end(), begin, end);
	else
		throw Span::SpanFullException();
}

int	Span::shortestSpan( void ) {
	if (this->_v.size() < 2) {
		throw Span::SpanTooShortException();
	}
	std::vector<int>	tmp;
	for (std::vector<int>::iterator it = this->_v.begin(); it != this->_v.end(); it++)
		tmp.push_back(*it);
	std::sort(tmp.begin(), tmp.end());
	int	span = tmp[1] - tmp[0];
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		if (span > *(it + 1) - *it)
			span = *(it + 1) - *it;
	}
	return span;
}

int	Span::longestSpan( void ) {
	if (this->_v.size() < 2) {
		throw Span::SpanTooShortException();
	}
	std::vector<int>	tmp;
	for (std::vector<int>::iterator it = this->_v.begin(); it != this->_v.end(); it++)
		tmp.push_back(*it);
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}
