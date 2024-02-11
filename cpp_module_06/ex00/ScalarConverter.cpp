/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:44:45 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 15:31:46 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
//temporaray header for printf
#include <cstdio>

void	ScalarConverter::convertToChar(std::string &literal) {
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		std::cout << "char: '" << literal << "'" << std::endl;
		return ;
	}
	int	nbr;
	std::istringstream	iss(literal);
	iss >> nbr;
	if (iss.fail() || nbr < 0 || nbr > 127) {
		iss.clear();
		iss.seekg(0);
		std::cerr << "char: impossible" << std::endl;
		return ;
	}
	if (std::isprint(nbr)) {
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
	return ;
}

void	ScalarConverter::convertToInt(std::string &literal) {
	int		i;
	std::istringstream	iss(literal);
	iss >> i;
	if (iss.fail()) {
		iss.clear();
		iss.seekg(0);
		std::cerr << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << i << std::endl;
	}
	return ;
}

void	ScalarConverter::convertToFloat(std::string &literal) {
	double	f;
	std::istringstream	iss(literal);
	iss >> f;
	if (iss.fail()) {
		iss.clear();
		iss.seekg(0);
		return ;
	}
	
	std::cout	<< "float: " << std::setprecision(10) << f;
	float	intPart;
	float	fractionPart = std::modf(f, &intPart);
	if (fractionPart == 0.0) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
	return ;
}

void	ScalarConverter::convertToDouble(std::string &literal) {
	double	d;
	std::istringstream	iss(literal);
	iss >> d;
	if (iss.fail()) {
		iss.clear();
		iss.seekg(0);
		std::cerr << "double: nan" << std::endl;
	}
	else {
		std::cout	<< "double: " << d;
		double	intPart;
		double	fractionPart = std::modf(d, &intPart);
		if (fractionPart == 0.0) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	}
	return ;
}

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

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {return ;}
