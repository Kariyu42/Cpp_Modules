/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:44:45 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/21 16:32:56 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convertToChar(std::string &literal) {
	//* if literal is nan, nanf, +inf, -inf, +inff, -inff, then impossible
	if (literal == "nan" || literal == "nanf" || literal == "+inf" \
		|| literal == "-inf" || literal == "+inff" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	//* if literal is a char, then display the char
	if (literal.length() == 1 && !std::isdigit(literal[0]) && IS_PRINTABLE(literal[0])) {
		std::cout << "char: '" << literal << "'" << std::endl;
		return ;
	}
	//* if literal is a number, then display the char
	
	std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::convertToInt(std::string &literal) {

}

void	ScalarConverter::convertToFloat(std::string &literal) {

}

void	ScalarConverter::convertToDouble(std::string &literal) {
	
}


/*
* ./convert a
* char: 'a'
* int: 97
* float: 97.0f
* double: 97.0
* ./convert 0
* char: Non displayable
* int: 0
* float: 0.0f
* double: 0.0
* ./convert nan
* char: impossible
* int: impossible
* float: nanf
* double: nan
* ./convert 42.0f
* char: '*'
* int: 42
* float: 42.0f
* double: 42.0
* must also these pseudo literals for double -inf, +inf and nan.
* and for float -inff, +inff and nanf.
*/
void	ScalarConverter::convert(std::string &literal) {
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
	return ;
}

ScalarConverter::ScalarConverter() {return ;}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	*this = other;
	return ;
}

ScalarConverter::~ScalarConverter() {return ;}

double	ScalarConverter::_strToDouble(std::string &literal) {
	double	nbr;
	std::stringstream	ss(literal);
	ss >> nbr;
	return nbr;
}

int	ScalarConverter::_strToInt(std::string &literal) {
	int	nbr;
	std::stringstream	ss(literal);
	ss >> nbr;
	return nbr;
}

float	ScalarConverter::_strToFloat(std::string &literal) {
	float	nbr;
	std::stringstream	ss(literal);
	ss >> nbr;
	return nbr;
}

char	ScalarConverter::_strToChar(std::string &literal) {
	char	c;
	std::stringstream	ss(literal);
	ss >> c;
	return c;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return *this;
}
