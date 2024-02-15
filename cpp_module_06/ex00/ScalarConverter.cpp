/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:44:45 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/14 19:27:42 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
//temporaray header for printf
#include <cstdio>

void	ScalarConverter::convertToChar(std::string &literal) {

	if (literal == "nan" || literal == "nanf" || literal == "+inf" \
		|| literal == "+inff" || literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		return ;
	}

	else if (literal.length() == 1 && !std::isdigit(literal[0])) {
		std::cout << "char: '" << literal << "'" << std::endl;
		return ;
	}

	int		nbr;
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
		return ;
	}

	std::cout << "char: Non displayable" << std::endl;
	return ;
}

void	ScalarConverter::convertToInt(std::string &literal) {

	if (literal == "nan" || literal == "+inf" || literal == "-inf" \
		|| literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "int: impossible" << std::endl;
		return ;
	}

	else if (literal.length() == 1 && !std::isdigit(literal[0])) {
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		return ;
	}

	int					i;
	std::istringstream	iss(literal);

	iss >> i;
	if (iss.fail()) {
		iss.clear();
		iss.seekg(0);
		std::cerr << "int: impossible" << std::endl;
		return ;
	}

	std::cout << "int: " << i << std::endl;
	return ;
}

void	ScalarConverter::convertToFloat(std::string &literal) {

	if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		std::cout << "float: " << literal << "f" << std::endl;
		return ;
	}
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "float: " << literal << std::endl;
		return ;
	}

	else if (literal.length() == 1 && !std::isdigit(literal[0])) {
		std::cout	<< "float: " << static_cast<float>(literal[0]) \
					<< ".0f" << std::endl;
		return ;
	}

	double				f;
	std::istringstream	iss(literal);

	iss >> f;
	// if (iss.fail()) {
	// 	iss.clear();
	// 	iss.seekg(0);
	// 	std::cout	<< "float: " << "impossible" << std::endl;
	// 	return ;
	// }

	std::cout	<< "float: " << std::setprecision(10) << f;

	double	intPart;
	double	fractionPart = std::modf(f, &intPart);

	if (fractionPart == 0.0) {
		std::cout << ".0";
	}

	std::cout << "f" << std::endl;
	return ;
}

void	ScalarConverter::convertToDouble(std::string &literal) {

	if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		std::cout << "double: " << literal << std::endl;
		return ;
	}
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
		return ;
	}

	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		std::cout	<< "double: " << static_cast<double>(literal[0]) \
					<< ".0" << std::endl;
		return ;
	}

	double				d;
	std::istringstream	iss(literal);

	iss >> d;
	// if (iss.fail()) {
	// 	iss.clear();
	// 	iss.seekg(0);
	// 	std::cout	<< "double: " << "impossible" << std::endl;
	// 	return ;
	// }
	
	std::cout	<< "double: " << std::setprecision(10) << d;
	
	double	intPart;
	double	fractionPart = std::modf(d, &intPart);

	if (fractionPart == 0.0) {
		std::cout << ".0";
	}

	std::cout << std::endl;
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
