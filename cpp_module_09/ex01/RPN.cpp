/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:24 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/19 16:57:02 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {return ;}

RPN::RPN(RPN const &rpn) {
	*this = rpn;
	return ;
}

RPN::~RPN() {return ;}

const char	*RPN::InvalidNumber::what() const throw() {
	return "Error: invalid number in RPN string. Must be between -9 and 9.";
}

const char	*RPN::FormatError::what() const throw() {
	return "Error: invalid format in RPN string.";
}

const char	*RPN::OperatorError::what() const throw() {
	return "Error: invalid operator in RPN string.";
}

const char	*RPN::ZeroDivision::what() const throw() {
	return "Error: division by zero.";
}

int	RPN::_strToInt(std::string str)
{
	std::istringstream	iss(str);
	int					n;

	iss >> n;
	return n;
}

bool	RPN::_checkNbr(int n)
{
	if (n > 9 || n < -9)
		return false;
	return true;
}

long	RPN::execRPN(std::string str) {
	std::istringstream	iss(str);
	std::string			token;
	int					nbr;

	while (iss >> token) {
		if (std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1]))) {
			nbr = _strToInt(token);
			if (!_checkNbr(nbr))
				throw RPN::InvalidNumber();
			this->_stack.push(nbr);
		}
		else {
			int		n1, n2;

			if (this->_stack.size() < 2)
				throw RPN::FormatError();

			n1 = this->_stack.top();
			this->_stack.pop();
			n2 = this->_stack.top();
			this->_stack.pop();
			
			switch (token[0]) {
				case '+':
					this->_stack.push(n2 + n1);
					break;
				case '-':
					this->_stack.push(n2 - n1);
					break;
				case '*':
					this->_stack.push(n2 * n1);
					break;
				case '/':
					if (n1 == 0)
						throw RPN::ZeroDivision();
					this->_stack.push(n2 / n1);
					break;
				default:
					throw RPN::OperatorError();
			}
		}
	}

	if (this->_stack.size() != 1)
		throw RPN::FormatError();

	return this->_stack.top();
}

RPN	&RPN::operator=(RPN const &rpn)
{
	this->_stack = rpn._stack;
	return *this;
}
